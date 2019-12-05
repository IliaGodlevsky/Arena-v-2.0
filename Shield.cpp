#include <iostream>

#include "Shield.h"
#include "Unit.h"

Shield::Shield(std::string name, int armor,
	int reflectChance)
	: Armor(name, armor), 
	m_reflectChance(reflectChance)
{

}

void Shield::showFullInfo()const
{
	Armor::showFullInfo();
	std::cout << "Reflect chance: " << m_reflectChance << std::endl;
}

bool Shield::isReflectChance()const
{
	return PosibilityCounter(m_reflectChance);
}



TowerShield::TowerShield(std::string name, int armor,
	Vitals health, int reflectChance)
	: Shield(name, armor,reflectChance), m_health(health)
{

}

void TowerShield::putOn(Unit& unit)const
{
	Armor::putOn(unit);
	unit.m_health = unit.m_health + this->m_health;
}

void TowerShield::putOff(Unit& unit)const
{
	Armor::putOff(unit);
	unit.m_health = unit.m_health - this->m_health;
}

void TowerShield::showFullInfo()const
{
	Shield::showFullInfo();
	std::cout << "Health add: " << this->m_health << std::endl;
}


LegionShield::LegionShield( std::string name, 
	int armor, Vitals health,Vitals mana, int reflectChance)
	: Shield(name, armor, reflectChance),
	m_health(health),
	m_mana(mana)
{

}

void LegionShield::putOn(Unit& unit)const
{
	Armor::putOn(unit);
	unit.m_health = unit.m_health + this->m_health;
	unit.m_mana = unit.m_mana + this->m_mana;
}

void LegionShield::putOff(Unit& unit)const
{
	Armor::putOff(unit);
	unit.m_health = unit.m_health - this->m_health;
	unit.m_mana = unit.m_mana - this->m_mana;
}

void LegionShield::showFullInfo()const
{
	Shield::showFullInfo();
	std::cout << "Health add: " << this->m_health << std::endl;
	std::cout << "Mana add: " << this->m_mana << std::endl;
}

