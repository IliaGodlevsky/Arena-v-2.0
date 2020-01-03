#include "Shield.h"

#include "../Unit/Unit.h"
#include "../PossibilityCounter/PosibilityCounter.h"

Shield::Shield(std::string name, int armor,
	int reflectChance)
	: m_name(name), m_reflectChance(reflectChance), m_armor(name, armor)
{

}


void Shield::putOn(Unit& unit)const
{
	m_armor.putOn(unit);
}

void Shield::putOff(Unit& unit)const
{
	m_armor.putOff(unit);
}

void Shield::showFullInfo()const
{
	m_armor.showFullInfo();
	std::cout << "Reflect chance: " << m_reflectChance << std::endl;
}

void Shield::showShortInfo()
{

	std::cout << "<" << m_name << ": " << m_armor.getArmor()
		<< "\\" << m_reflectChance << ">\n";
}

bool Shield::isReflectChance()const
{
	return PosibilityCounter(m_reflectChance);
}

ShieldPtr Shield::clone()const
{
	return ShieldPtr(new Shield(m_name, m_armor.getArmor(), m_reflectChance));
}

ShieldPtr Shield::getPureShield()const
{
	const int ZERO_REFLCET_CHANCE = 0;
	return ShieldPtr(new Shield(m_name, m_armor.getArmor(), ZERO_REFLCET_CHANCE));
}