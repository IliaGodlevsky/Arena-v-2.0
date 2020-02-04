#include "LegionerChains.h"
#include "../Unit/Unit.h"

LegionerChains::LegionerChains(std::string name, int armor,
	Vitals health, Vitals mana) : Armor(name, armor),
	m_health(health), m_mana(mana)
{

}

void LegionerChains::putOn(Unit& unit)const
{
	Armor::putOn(unit);
	unit.m_health = unit.m_health + m_health;
	unit.m_mana = unit.m_mana + m_mana;
}

void LegionerChains::putOff(Unit& unit)const
{
	Armor::putOff(unit);
	unit.m_health = unit.m_health - m_health;
	unit.m_mana = unit.m_mana - m_mana;
}

void LegionerChains::showFullInfo()const
{
	Armor::showFullInfo();
	std::cout << "Health add: " << m_health << std::endl;
	std::cout << "Mana add: " << m_mana << std::endl;
}

ArmPtr LegionerChains::clone()const
{
	return ArmPtr(new LegionerChains(m_name, m_armor, m_health, m_mana));
}