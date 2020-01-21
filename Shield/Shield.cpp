#include "Shield.h"

#include "../Unit/Unit.h"
#include "../Magic/Elements/HpReduceElem.h"
#include "../UnitState/InnerUnitState/DeadUnitState.h"
#include "../PossibilityCounter/PosibilityCounter.h"

Shield::Shield(std::string name, int armor, int reflectChance)
	: m_name(name), m_armor(name, armor), m_reflectChance(reflectChance)
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
}

void Shield::showShortInfo()const
{
	std::cout << "<" << m_name << ": " << m_armor.getArmor() 
		<< "\\" << m_reflectChance << ">\n";
}

ShieldPtr Shield::clone()const
{
	return ShieldPtr(new Shield(m_name, m_armor.getArmor(), m_reflectChance));
}

ShieldPtr Shield::getPureShield()const
{
	const int ZERO_REFLCET_CHANCE = 0;
	return ShieldPtr(new Shield(m_name, m_armor.getArmor()));
}

bool Shield::takeDamage(Unit& unit, int damage)const
{
	if (PosibilityCounter(m_reflectChance))
	{
		std::cout << "But attack was reflected\n";
		return false;
	}
	HpReduceElem(calculateDamageAbsorb(unit.m_armor, damage)).effectUnit(unit);
	return true;
}

bool Shield::takeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const
{
	magic->effectUnit(unit);
	return true;
}

int Shield::calculateDamageAbsorb(int armor, int damage)const
{
	// The formula is taken from WarCraft 3
	const double REDUCE_CONST = 0.06;
	const double numerator = static_cast<double>(armor * REDUCE_CONST);
	double percent_of_reduce = numerator / (1.0 + numerator);
	return static_cast<int>(std::floor(damage * (1.0 - percent_of_reduce)));
}