#include "Shield.h"
#include "../Unit/Unit.h"

Shield::Shield(std::string name, int armor,
	int reflectChance)
	: m_name(name), m_reflectChance(reflectChance), m_armor(armor)
{

}


void Shield::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(this->m_armor);
}

void Shield::putOff(Unit& unit)const
{
	unit.m_armor.changeValue(-this->m_armor);
}

void Shield::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Armor: " << m_armor << std::endl;
	std::cout << "Reflect chance: " << m_reflectChance << std::endl;
}

void Shield::showShortInfo()
{
	std::cout << "<" << m_name << ">" << std::endl;
}

bool Shield::isReflectChance()const
{
	return PosibilityCounter(m_reflectChance);
}

ShieldPtr Shield::clone()const
{
	return ShieldPtr(new Shield(m_name, m_armor, m_reflectChance));
}