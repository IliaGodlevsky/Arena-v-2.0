#include "ArmorAndDamageDebuffMagic.h"

ArmorAndDamageDebuffMagic::ArmorAndDamageDebuffMagic(std::string name,
	int manaCost, const Timer& timer, int armorReduce, int damageReduce)
	: Magic(name, manaCost, timer),
	ArmorDebuffMagic(name, manaCost, timer, armorReduce),
	DamageDebuffMagic(name, manaCost, timer, damageReduce)
{

}

void ArmorAndDamageDebuffMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorAndDamageDebuffMagic::uneffectUnit(Unit& unit)const
{
	DamageDebuffMagic::uneffectUnit(unit);
	ArmorDebuffMagic::uneffectUnit(unit);
}

MagicPtr ArmorAndDamageDebuffMagic::clone()const
{
	return MagicPtr(new ArmorAndDamageDebuffMagic(m_name, m_manaCost,
		m_timer, m_armorReduce, m_damageReduce));
}
bool ArmorAndDamageDebuffMagic::isBuff()const
{
	return false;
}

bool ArmorAndDamageDebuffMagic::hasEqualParametres(const MagicPtr& magic)const
{
	return ArmorDebuffMagic::hasEqualParametres(magic)
		&& DamageDebuffMagic::hasEqualParametres(magic);
}

bool ArmorAndDamageDebuffMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorAndDamageDebuffMagic::putOn(Unit& unit)const
{
	DamageDebuffMagic::putOn(unit);
	ArmorDebuffMagic::putOn(unit);
}

void ArmorAndDamageDebuffMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void ArmorAndDamageDebuffMagic::showData()const
{
	ArmorDebuffMagic::showData();
	DamageDebuffMagic::showData();
}