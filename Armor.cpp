#include <iostream>

#include "Armor.h"
#include "Unit.h"

Armor::Armor(std::string name, int armor)
	: m_armor(armor), m_name(name)
{

}

void Armor::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(this->m_armor);
}

void Armor::putOff(Unit& unit)const
{
	unit.m_armor.changeValue(-this->m_armor);
}

void Armor::showShortInfo()const
{
	std::cout << "<" << this->m_name << ">\n";
}

void Armor::showFullInfo()const
{
	std::cout << "Name: " << this->m_name << std::endl;
	std::cout << "Armor: " << this->m_armor << std::endl;
}

ArmPtr Armor::clone()const
{
	return ArmPtr(new Armor(m_name, m_armor));
}

Mail::Mail(std::string name, int armor, Vitals health)
	: Armor(name, armor), m_health(health)
{

}

void Mail::putOn(Unit& unit)const
{
	Armor::putOn(unit);
	unit.m_health = unit.m_health + this->m_health;
}

void Mail::putOff(Unit& unit)const
{
	Armor::putOff(unit);
	unit.m_health = unit.m_health - this->m_health;
}

void Mail::showFullInfo()const
{
	Armor::showFullInfo();
	std::cout << "Health add: " << this->m_health << std::endl;
}

ArmPtr Mail::clone()const
{
	return ArmPtr(new Mail(m_name, m_armor, m_health));
}

WizardCloak::WizardCloak(std::string name, int armor, Vitals mana)
	: Armor(name, armor), m_mana(mana)
{

}

void WizardCloak::putOn(Unit& unit)const
{
	Armor::putOn(unit);
	unit.m_mana = unit.m_mana + this->m_mana;
}

void WizardCloak::putOff(Unit& unit)const
{
	Armor::putOff(unit);
	unit.m_mana = unit.m_mana - this->m_mana;
}

void WizardCloak::showFullInfo()const
{
	Armor::showFullInfo();
	std::cout << "Mana add: " << this->m_mana << std::endl;
}

ArmPtr WizardCloak::clone()const
{
	return ArmPtr(new WizardCloak(m_name, m_armor, m_mana));
}

LegionerChains::LegionerChains(std::string name, int armor,
	Vitals health, Vitals mana) : Armor(name, armor),
	m_health(health), m_mana(mana)
{

}

void LegionerChains::putOn(Unit& unit)const
{
	Armor::putOn(unit);
	unit.m_health = unit.m_health + this->m_health;
	unit.m_mana = unit.m_mana + this->m_mana;
}

void LegionerChains::putOff(Unit& unit)const
{
	Armor::putOff(unit);
	unit.m_health = unit.m_health - this->m_health;
	unit.m_mana = unit.m_mana - this->m_mana;
}

void LegionerChains::showFullInfo()const
{
	Armor::showFullInfo();
	std::cout << "Health add: " << this->m_health << std::endl;
	std::cout << "Mana add: " << this->m_mana << std::endl;
}

ArmPtr LegionerChains::clone()const
{
	return ArmPtr(new LegionerChains(m_name, m_armor, m_health, m_mana));
}