#include "OffsetDamageBuff.h"

OffsetDamageBuff::OffsetDamageBuff(std::string name, int manaCost,
	int duration, int armorReduce, int damageAmplify)
	: Magic(name, manaCost, duration),
	DamageBuff(name, manaCost, duration, damageAmplify),
	ArmorDebuff(name, manaCost, duration, armorReduce)
{

}

void OffsetDamageBuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void OffsetDamageBuff::uneffectUnit(Unit& unit)const
{
	DamageBuff::uneffectUnit(unit);
	ArmorDebuff::uneffectUnit(unit);
}

MagicPtr OffsetDamageBuff::clone()const
{
	return MagicPtr(new OffsetDamageBuff(m_name, m_manaCost, m_durationmeter,
		m_armorReduce, m_damageAmplify));
}

bool OffsetDamageBuff::isBuff()const
{
	return true;
}

bool OffsetDamageBuff::hasEqualParametres(const MagicPtr& magic)const
{
	return ArmorDebuff::hasEqualParametres(magic)
		&& DamageBuff::hasEqualParametres(magic);
}

bool OffsetDamageBuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void OffsetDamageBuff::putOn(Unit& unit)const
{
	DamageBuff::putOn(unit);
	ArmorDebuff::putOn(unit);
}

void OffsetDamageBuff::showFullInfo()const
{
	Magic::showData();
	showData();
}


void OffsetDamageBuff::showData()const
{
	DamageBuff::showData();
	ArmorDebuff::showData();
}