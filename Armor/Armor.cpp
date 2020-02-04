#include "Armor.h"
#include "../Unit/Unit.h"

Armor::Armor(std::string name, int armor)
	: m_armor(armor), m_name(name)
{

}

void Armor::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(m_armor);
}

void Armor::putOff(Unit& unit)const
{
	unit.m_armor.changeValue(-m_armor);
}

void Armor::showShortInfo()const
{
	std::cout << "<" << m_name << ": " << m_armor << ">\n";
}

void Armor::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Armor: " << m_armor << std::endl;
}

ArmPtr Armor::clone()const
{
	return ArmPtr(new Armor(m_name, m_armor));
}

int Armor::getArmor()const
{
	return m_armor;
}
