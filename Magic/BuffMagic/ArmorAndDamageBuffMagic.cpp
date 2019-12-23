#include "ArmorAndDamageBuffMagic.h"

ArmorAndDamageBuffMagic::ArmorAndDamageBuffMagic(std::string name,
	int manaCost, const Timer& timer, int armorAmplify, int damageAmplify)
	: Magic(name, manaCost, timer),
	ArmorBuffMagic(name, manaCost, timer, armorAmplify),
	DamageBuffMagic(name, manaCost, timer, damageAmplify)
{

}

void ArmorAndDamageBuffMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorAndDamageBuffMagic::uneffectUnit(Unit& unit)const
{
	DamageBuffMagic::uneffectUnit(unit);
	ArmorBuffMagic::uneffectUnit(unit);
}

MagicPtr ArmorAndDamageBuffMagic::clone()const
{
	return MagicPtr(new ArmorAndDamageBuffMagic(m_name, m_manaCost, m_timer,
		m_armorAmplify, m_damageAmplify));
}

bool ArmorAndDamageBuffMagic::isBuff()const
{
	return true;
}

bool ArmorAndDamageBuffMagic::hasEqualParametres(const MagicPtr& magic)const
{
	return ArmorBuffMagic::hasEqualParametres(magic)
		&& DamageBuffMagic::hasEqualParametres(magic);
}

bool ArmorAndDamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorAndDamageBuffMagic::putOn(Unit& unit)const
{
	DamageBuffMagic::putOn(unit);
	ArmorBuffMagic::putOn(unit);
}

void ArmorAndDamageBuffMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void ArmorAndDamageBuffMagic::showData()const
{
	ArmorBuffMagic::showData();
	DamageBuffMagic::showData();
}