#include <iostream>
#include <ctime>

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Decision/Decision.h"
#include "../Decision/HumanDecision.h"

#include "Arena.h"


int Arena::m_round = 0;

int Arena::getMaxNubmerOfPlayers()const
{
	return 5;
}

int Arena::getMinNumberOfPlayers()const
{
	return 2;
}

Arena::Arena()
{
	m_units.resize(setNumberOfUnits());
}


int Arena::setNumberOfUnits()const
{
	return inputNumber("Set number of players: ",
		getMaxNubmerOfPlayers(), getMinNumberOfPlayers());
}

int Arena::getCurrentRound()
{
	return m_round;
}

Arena& Arena::getInstance()
{
	static Arena instance;
	return instance;
}

void Arena::showUnits()const
{
	for (size_t i = 0; i < m_units.size(); i++)
	{
		std::cout << i + 1 << ". ";
		m_units[i]->showFullInfo();
	}
	std::cout << std::endl;
}

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
	char ch = 'a';
	std::vector<std::string> names(m_units.size());
	for (size_t i = 0; i < names.size(); i++)
		names[i] = ch++;
	for (size_t i = 0; i < m_units.size(); i++)
	{
		m_units[i] = UnitPtr(new Unit(names[i], 
			std::shared_ptr<Decision>(new HumanDecision())));
	}
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
	if (!m_unitToCast->isAlive())
		m_units[m_unitIndex]->levelUp();
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