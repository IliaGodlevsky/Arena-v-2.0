#include "Magic.h"

#include "../Arena/Arena.h"
#include "../Unit/Unit.h"

Magic::Magic(std::string name, int manaCost, const Timer& timer)
	: m_name(name), m_manaCost(manaCost), m_timer(timer)
{

}

Magic::~Magic() {}

void Magic::effectUnit(Unit& unit)
{
	setStartTime(Arena::getCurrentRound());
	unit.m_magicOnMe.takeMagic(clone());
}

bool Magic::isExpired(int round)const
{
	return m_timer.isExpired(round);
}

void Magic::setStartTime(int round)
{
	m_timer.setStartTime(round);
}

bool Magic::isEnoughMana(int currentUnitMana)const
{
	return currentUnitMana >= m_manaCost;
}

bool Magic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	return m_name == magic->m_name
		&& m_manaCost == magic->m_manaCost
		&& m_timer == magic->m_timer;
}

bool Magic::isEqual(const MagicPtr& magic)const
{
	return hasEqualParametres(magic);
}

int Magic::getCost()const
{
	return m_manaCost;
}

void Magic::showData()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Mana cost: " << m_manaCost << std::endl;
	std::cout << "Duration: " << m_timer.getDuration() << std::endl;
}

void Magic::showFullInfo()const
{
	showData();
}

void Magic::showShortInfo()const
{
	std::cout << "<" << m_name << ": " << m_manaCost << "> ";
}

const std::string& Magic::getName()const
{
	return m_name;
}
