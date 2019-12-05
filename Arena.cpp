#include <iostream>
#include <ctime>

#include "Arena.h"
#include "MagicFactory.h"
#include "WeaponFactory.h"
#include "ArmorFactory.h"

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
	std::srand(std::time(nullptr));
	m_units.resize(setNumberOfUnits());
	// Give items to units
	// Give units names
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

bool Arena::gameOver()const
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
			std::shared_ptr<Decision>(new HumanDecision(m_units))));
	}
}

void Arena::giveMagicToUnits(const AllItemFactory<Magic>& magicFactory)
{
	for (size_t i = 0; i < m_units.size(); i++)
		m_units[i]->takeMagic(magicFactory);
}

void Arena::giveWeaponToUnits(const AllItemFactory<Weapon>& weaponFactory)
{
	for (size_t i = 0; i < m_units.size(); i++)
		m_units[i]->takeWeapon(weaponFactory);
}

void Arena::giveArmorToUnits(const AllItemFactory<Armor>& armorFactory)
{
	for (size_t i = 0; i < m_units.size(); i++)
		m_units[i]->takeArmor(armorFactory);
}

void Arena::giveShieldToUnits(const AllItemFactory<Shield>& sheildFactory)
{
	for (size_t i = 0; i < m_units.size(); i++)
		m_units[i]->takeShield(sheildFactory);
}

void Arena::castStep()
{
	showUnits();
	m_magicToCast = m_units[m_unitIndex]->chooseMagicToCast();
	m_unitToCast = m_units[m_unitIndex]->chooseUnitToCast(m_magicToCast);
	if (nullptr != m_unitToCast && nullptr != m_magicToCast)
		m_units[m_unitIndex]->castMagic(*m_unitToCast, m_magicToCast);
}

void Arena::attackStep()
{
	showUnits();
	m_unitToAttack = m_units[m_unitIndex]->chooseUnitToAttack();
	if (nullptr != m_unitToAttack)
		m_units[m_unitIndex]->injureUnit(*m_unitToAttack);
}

void Arena::rewardKiller()
{
	if (!m_unitToCast->isAlive())
		m_units[m_unitIndex]->levelUp();
}

void Arena::nextPlayer()
{
	m_unitIndex++;
	if (m_unitIndex >= m_units.size())
	{
		m_unitIndex = 0;
		m_round++;
	}
}

void Arena::newRound()
{
	for (size_t i = 0; i < m_units.size(); i++)
		m_units[i]->moveIntoNewRound();
}