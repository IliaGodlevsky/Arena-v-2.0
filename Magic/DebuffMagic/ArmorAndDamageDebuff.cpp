#include "ArmorAndDamageDebuff.h"

ArmorAndDamageDebuff::ArmorAndDamageDebuff(std::string name,
	int manaCost, int duration, int armorReduce, int damageReduce)
	: Magic(name, manaCost, duration),
	ArmorDebuff(name, manaCost, duration, armorReduce),
	DamageDebuff(name, manaCost, duration, damageReduce)
{

}

void ArmorAndDamageDebuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorAndDamageDebuff::uneffectUnit(Unit& unit)const
{
	DamageDebuff::uneffectUnit(unit);
	ArmorDebuff::uneffectUnit(unit);
}

MagicPtr ArmorAndDamageDebuff::clone()const
{
	return MagicPtr(new ArmorAndDamageDebuff(m_name, m_manaCost,
		m_durationmeter, m_armorReduce, m_damageReduce));
}
bool ArmorAndDamageDebuff::isBuff()const
{
	return false;
}

bool ArmorAndDamageDebuff::hasEqualParametres(const MagicPtr& magic)const
{
	return ArmorDebuff::hasEqualParametres(magic)
		&& DamageDebuff::hasEqualParametres(magic);
}

bool ArmorAndDamageDebuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorAndDamageDebuff::putOn(Unit& unit)const
{
	DamageDebuff::putOn(unit);
	ArmorDebuff::putOn(unit);
}

void ArmorAndDamageDebuff::showFullInfo()const
{
	Magic::showData();
	showData();
}

void ArmorAndDamageDebuff::showData()const
{
	ArmorDebuff::showData();
	DamageDebuff::showData();
}