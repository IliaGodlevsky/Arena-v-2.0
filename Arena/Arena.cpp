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
	return 7;
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
	std::cout << "Welcome to Arena\n";
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
			if (m_unitIndex > i)
				--m_unitIndex;
			i--;
		}
	}
}

bool Arena::isGameOver()const
{
	size_t alliesCount = 0;
	for (size_t i = 0; i < m_units.size(); i++)
		if(m_units[0]->isAlly(m_units[i]))
			alliesCount++;
	return alliesCount == m_units.size()
		|| m_units.size() == 1;
}

void Arena::prepareUnits()
{
	std::vector<std::string> unitsNames;
	std::thread thread([&unitsNames]() { unitsNames = loadFromFile("Names.txt"); });
	if (unitsNames.empty())
		unitsNames = m_reserveNames;
	auto unitGenerator = [&unitsNames, &thread]()
	{	
		enum { WARRIOR = 1, WIZARD };
		std::vector<UnitFactoryPtr> unitFactories({ 
			UnitFactoryPtr(new WarriorFactory()),
			UnitFactoryPtr(new WizardFactory()) });
		index factoryNumber = inputNumber("1. Warrior 2. "
			"Wizard\nChoose unit type: ", WIZARD, WARRIOR);
		UnitPtr unit = unitFactories[factoryNumber - 1]->createUnit();
		if (thread.joinable())
			thread.join();
		unit->setName(unitsNames[randomNumber(unitsNames.size() - 1)]);
		system("cls");
		return unit;
	};
	std::generate(m_units.begin(), m_units.end(), unitGenerator);
}

void Arena::proposeToPlayTeams()
{
	if (m_units.size() > 2)
	{
		const bool answer = static_cast<bool>(inputNumber("Do you want play "
			"with teams? <1 - yes, 0 - no>: ", YES, NO));
		if (YES == answer)
		{
			size_t teamsNumber = inputNumber("Enter teams"
				" number: ", m_units.size(), 2);
			std::vector<Gladiators> teams = breakIntoTeams(teamsNumber);
			setAllies(teams);
			pushAlliesToArena(teams);
		}
	}
}

std::vector<Gladiators> Arena::breakIntoTeams(size_t teamsNumber)
{
	
	index unitIndex;
	const size_t QUIT = 0;
	const size_t LIMIT = m_units.size();
	std::vector<Gladiators> teams;
	for (size_t i = 0; i < teamsNumber; i++)
	{
		teams.resize(i + 1);
		for (size_t j = 0; j < LIMIT; j++)
		{
			showUnits();
			unitIndex = inputNumber("Choose unit for " + std::to_string(i + 1)
				+ " team" + " (0 to stop): ", m_units.size(), QUIT);
			if (QUIT == unitIndex || m_units.empty())
				break;
			teams[i].push_back(m_units[unitIndex - 1]);
			m_units.erase(m_units.begin() + (unitIndex - 1));
			if (m_units.size() == (teamsNumber - i - 1))
				break;
			system("cls");
		}
	}
	return teams;
}

void Arena::setAllies(std::vector<Gladiators>& teams)const
{
	for (size_t i = 0; i < teams.size(); i++)
		for (size_t j = 0; j < teams[i].size(); j++)
			for (size_t l = 0; l < teams[i].size(); l++)
				teams[i][l]->takeAlly(teams[i][j]);
}

void Arena::pushAlliesToArena(const std::vector<Gladiators>& teams)
{
	for (size_t i = 0; i < teams.size(); i++)
		for (size_t j = 0; j < teams[i].size(); j++)
			m_units.push_back(teams[i][j]);
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
		rewardKiller(m_unitToCast);
	}
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
			rewardKiller(m_unitToAttack);
		}
	}
}

void Arena::rewardKiller(UnitPtr victim)
{
	if (!victim->isAlive())
	{
		std::cout << m_units[m_unitIndex]->getName() << " slashed " << 
			victim->getName() << std::endl;
		m_units[m_unitIndex]->levelUp();
		m_units[m_unitIndex]->takeKilledUnitMagic(*victim);
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
	for (auto unit : m_units)
		unit->moveIntoNewRound();
}