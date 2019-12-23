#include "OffsetDamageBuffMagic.h"

OffsetDamageBuffMagic::OffsetDamageBuffMagic(std::string name, int manaCost,
	const Timer& timer, int armorReduce, int damageAmplify)
	: Magic(name, manaCost, timer),
	DamageBuffMagic(name, manaCost, timer, damageAmplify),
	ArmorDebuffMagic(name, manaCost, timer, armorReduce)
{

}

void OffsetDamageBuffMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void OffsetDamageBuffMagic::uneffectUnit(Unit& unit)const
{
	DamageBuffMagic::uneffectUnit(unit);
	ArmorDebuffMagic::uneffectUnit(unit);
}

MagicPtr OffsetDamageBuffMagic::clone()const
{
	return MagicPtr(new OffsetDamageBuffMagic(m_name, m_manaCost, m_timer,
		m_armorReduce, m_damageAmplify));
}

bool OffsetDamageBuffMagic::isBuff()const
{
	return true;
}

bool OffsetDamageBuffMagic::hasEqualParametres(const MagicPtr& magic)const
{
	return ArmorDebuffMagic::hasEqualParametres(magic)
		&& DamageBuffMagic::hasEqualParametres(magic);
}

bool OffsetDamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void OffsetDamageBuffMagic::putOn(Unit& unit)const
{
	DamageBuffMagic::putOn(unit);
	ArmorDebuffMagic::putOn(unit);
}

void OffsetDamageBuffMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}


void OffsetDamageBuffMagic::showData()const
{
	DamageBuffMagic::showData();
	ArmorDebuffMagic::showData();
}