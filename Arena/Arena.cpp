#include <iostream>
#include <thread>

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Decision/Decision.h"
#include "../Decision/HumanDecision.h"
#include "../Factories/UnitFactory/UnitFactory.h"
#include "../Factories/UnitFactory/WarriorFactory.h"
#include "../Factories/UnitFactory/WizardFactory.h"

#include "Arena.h"


int Arena::m_round = 0;

// Return the maximum number of players
// that can take part in the game
constexpr int Arena::getMaxNubmerOfPlayers()const
{
	return 6;
}

constexpr int Arena::getMinNumberOfPlayers()const
{
	return 2;
}

Arena::Arena()
{
	showMiniature();
	m_units.resize(setNumberOfUnits());
}

void Arena::showMiniature()const
{
	std::cout << R"(
        ___           ___           ___           ___           ___     
       /\  \         /\  \         /\  \         /\__\         /\  \    
      /::\  \       /::\  \       /::\  \       /::|  |       /::\  \   
     /:/\:\  \     /:/\:\  \     /:/\:\  \     /:|:|  |      /:/\:\  \  
    /::\~\:\  \   /::\~\:\  \   /::\~\:\  \   /:/|:|  |__   /::\~\:\  \ 
   /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/ |:| /\__\ /:/\:\ \:\__\
   \/__\:\/:/  / \/_|::\/:/  / \:\~\:\ \/__/ \/__|:|/:/  / \/__\:\/:/  /
        \::/  /     |:|::/  /   \:\ \:\__\       |:/:/  /       \::/  / 
        /:/  /      |:|\/__/     \:\ \/__/       |::/  /        /:/  /  
       /:/  /       |:|  |        \:\__\         /:/  /        /:/  /   
       \/__/         \|__|         \/__/         \/__/         \/__/    
)";
}

// Sets number of players, that will play the game
int Arena::setNumberOfUnits()const
{
	return inputNumber("Set number of players: ",
		getMaxNubmerOfPlayers(), getMinNumberOfPlayers());
}

int Arena::getCurrentRound()
{
	return m_round;
}

// Returns the object of a class
Arena& Arena::getInstance()
{
	static Arena instance;
	return instance;
}

void Arena::showUnits()const
{
	system("pause"); system("cls");
	std::cout << "Round: " 
		<< getCurrentRound() + 1 << std::endl;
	for (size_t i = 0; i < m_units.size(); i++)
	{
		std::cout << i + 1 << ". ";
		m_units[i]->showFullInfo();
		std::cout << std::endl;
	}
}

// If some unit is dead, it will be
// removed from the game
void Arena::takeOfLosers()
{
	for (size_t i = 0; i < m_units.size(); i++)
	{
		if (!m_units[i]->isAlive())
		{
			m_units.erase(m_units.begin() + i);
			i--;

		}
	}
}

bool Arena::isGameOver()const
{
	return m_units.size() == 1;
}

void Arena::prepareUnits()
{
	std::vector<std::string> unitsNames;
	std::thread thread([&]() { unitsNames = loadFromFile("Names.txt"); });
	auto unitGenerator = [&unitsNames, &thread]()
	{	
		enum { WARRIOR = 1, WIZARD };
		std::vector<UnitFactoryPtr> unitFactories({ 
			UnitFactoryPtr(new WarriorFactory()),
			UnitFactoryPtr(new WizardFactory()) });
		index factoryNumber = inputNumber("1. Warrior 2. Wizard\nChoose unit type: ", WIZARD, WARRIOR);
		UnitPtr unit = unitFactories[factoryNumber - 1]->createUnit();
		if (thread.joinable())
			thread.join();
		unit->setName(unitsNames[randomNumber(unitsNames.size() - 1)]);
		return unit;
	};
	std::generate(m_units.begin(), m_units.end(), unitGenerator);
}

void Arena::playCastStep()
{
	m_magicToCast = m_units[m_unitIndex]->chooseMagicToCast(m_units);
	m_unitToCast = m_units[m_unitIndex]->chooseUnitToCast(m_magicToCast, m_units);
	if (nullptr != m_unitToCast && nullptr != m_magicToCast)
	{
		auto& messager = Messager::getIncstance();
		messager.writeMessage(m_units[m_unitIndex]->getName(),
			" charmed ", m_unitToCast->getName(),
			" with ", m_magicToCast->getName() + "\n");
		m_units[m_unitIndex]->castMagic(*m_unitToCast, m_magicToCast);
	}
	rewardKiller(m_unitToCast);
}

void Arena::playAttackStep()
{
	if (!isGameOver())
	{
		m_unitToAttack = m_units[m_unitIndex]->chooseUnitToAttack(m_units);
		if (nullptr != m_unitToAttack)
		{
			auto& messager = Messager::getIncstance();
			messager.writeMessage(m_units[m_unitIndex]->getName(),
				" attacked ", m_unitToAttack->getName() + "\n");
			m_units[m_unitIndex]->injureUnit(*m_unitToAttack);
		}
		rewardKiller(m_unitToAttack);
	}
}

void Arena::rewardKiller(UnitPtr victim)
{
	if (nullptr != victim)
	{
		if (!victim->isAlive())
		{
			std::cout << m_units[m_unitIndex]->getName() << " slashed " <<
				victim->getName() << std::endl;
			m_units[m_unitIndex]->levelUp();
			m_units[m_unitIndex]->takeKilledUnitMagic(*victim);
		}
	}
}

void Arena::goNextUnit()
{
	m_unitIndex++;
	if (m_unitIndex >= m_units.size())
	{
		m_unitIndex = 0;
		m_round++;
		goNewRound();
	}
}

void Arena::goNewRound()
{
	for (size_t i = 0; i < m_units.size(); i++)
		m_units[i]->moveIntoNewRound();
}