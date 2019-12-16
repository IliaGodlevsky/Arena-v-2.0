#include "ArmorAndDamageBuff.h"

ArmorAndDamageBuff::ArmorAndDamageBuff(std::string name,
	int manaCost, int duration, int armorAmplify, int damageAmplify)
	: Magic(name, manaCost, duration),
	ArmorBuff(name, manaCost, duration, armorAmplify),
	DamageBuff(name, manaCost, duration, damageAmplify)
{

}

void ArmorAndDamageBuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorAndDamageBuff::uneffectUnit(Unit& unit)const
{
	DamageBuff::uneffectUnit(unit);
	ArmorBuff::uneffectUnit(unit);
}

MagicPtr ArmorAndDamageBuff::clone()const
{
	return MagicPtr(new ArmorAndDamageBuff(m_name, m_manaCost, m_durationmeter,
		m_armorAmplify, m_damageAmplify));
}

bool ArmorAndDamageBuff::isBuff()const
{
	return true;
}

bool ArmorAndDamageBuff::hasEqualParametres(const MagicPtr& magic)const
{
	return ArmorBuff::hasEqualParametres(magic)
		&& DamageBuff::hasEqualParametres(magic);
}

bool ArmorAndDamageBuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorAndDamageBuff::putOn(Unit& unit)const
{
	DamageBuff::putOn(unit);
	ArmorBuff::putOn(unit);
}

void ArmorAndDamageBuff::showFullInfo()const
{
	Magic::showData();
	showData();
}

void ArmorAndDamageBuff::showData()const
{
	ArmorBuff::showData();
	DamageBuff::showData();
}