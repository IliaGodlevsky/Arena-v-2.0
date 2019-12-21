#include <iostream>
#include <ctime>

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Decision/Decision.h"
#include "../Decision/HumanDecision.h"
#include "../Factories/UnitFactory/UnitFactory.h"
#include "../Factories/ItemFactory/DefenceItemFactory.h"
#include "../Factories/ItemFactory/OffenceItemFactory.h"

#include "Arena.h"


int Arena::m_round = 0;

// Return the maximum number of players
// that can take part in the game
constexpr int Arena::getMaxNubmerOfPlayers()const
{
	return 5;
}

constexpr int Arena::getMinNumberOfPlayers()const
{
	return 2;
}

Arena::Arena()
{
	m_units.resize(setNumberOfUnits());
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
	system("cls");
	std::cout << "Round: "<< getCurrentRound() + 1 
		<< std::endl;
	for (size_t i = 0; i < m_units.size(); i++)
	{
		std::cout << i + 1 << ". ";
		m_units[i]->showFullInfo();
	}
	std::cout << std::endl;
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
	ItemFactory* defenceItemFactory = new DefenceItemFactory();
	ItemFactory* offenceItemFactory = new OffenceItemFactory();
	UnitFactory* unitFactory = new UnitFactory(defenceItemFactory);
	for (size_t i = 0; i < m_units.size(); i++)
	{
		// gives to unit armor, weapon, magic, shield, and sets decision
		if (i % 2 == 0)
			unitFactory->setFactory(defenceItemFactory);
		else
			unitFactory->setFactory(offenceItemFactory);
		m_units[i] = unitFactory->createUnit();
	}
	delete defenceItemFactory;
	delete offenceItemFactory;
	delete unitFactory;
}

void Arena::playCastStep()
{
	m_magicToCast = m_units[m_unitIndex]->chooseMagicToCast(m_units);
	m_unitToCast = m_units[m_unitIndex]->chooseUnitToCast(m_magicToCast, m_units);
	if (nullptr != m_unitToCast && nullptr != m_magicToCast)
		m_units[m_unitIndex]->castMagic(*m_unitToCast, m_magicToCast);
}

void Arena::playAttackStep()
{
	m_unitToAttack = m_units[m_unitIndex]->chooseUnitToAttack(m_units);
	if (nullptr != m_unitToAttack)
		m_units[m_unitIndex]->injureUnit(*m_unitToAttack);
}

void Arena::rewardKiller()
{
	if (nullptr != m_unitToCast)
	{
		if (!m_unitToCast->isAlive())
			m_units[m_unitIndex]->levelUp();
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