#include "../../Unit/Unit.h"

#include "DamageBuffMagic.h"

DamageBuffMagic::DamageBuffMagic(std::string name, int manaCost,
	const Timer& timer, int damageAmplify)
	: Magic(name, manaCost, timer),
	m_damageAmplify(damageAmplify)
{

}

void DamageBuffMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void DamageBuffMagic::uneffectUnit(Unit& unit)const
{
	unit.m_damage.changeValue(-m_damageAmplify);
}

MagicPtr DamageBuffMagic::clone()const
{
	return MagicPtr(new DamageBuffMagic(m_name, m_manaCost, m_timer, m_damageAmplify));
}

void DamageBuffMagic::putOn(Unit& unit)const
{
	unit.m_damage.changeValue(m_damageAmplify);
}

bool DamageBuffMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	DamageBuffMagic* temp = DYNAMIC(DamageBuffMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_damageAmplify == temp->m_damageAmplify;
}

bool DamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

bool DamageBuffMagic::isBuff()const
{
	return true;
}

void DamageBuffMagic::showData()const
{
	std::cout << "Damage add: " << m_damageAmplify << std::endl;
}

void DamageBuffMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}