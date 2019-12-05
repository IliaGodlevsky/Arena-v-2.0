#include <iostream>
#include <typeinfo>

#include "BuffMagic.h"
#include "DebuffMagic.h"
#include "Unit.h"

DamageBuff::DamageBuff(std::string name, int manaCost,
	int duration, int damageAmplify)
	: Magic(name, manaCost, duration),
	m_damageAmplify(damageAmplify)
{

}

void DamageBuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void DamageBuff::uneffectUnit(Unit& unit)const
{
	unit.m_damage.ChangeValue(-m_damageAmplify);
}

MagicPtr DamageBuff::clone()const
{
	return MagicPtr(new DamageBuff(m_name, m_manaCost, m_durationmeter, m_damageAmplify));
}

void DamageBuff::putOn(Unit& unit)const
{
	unit.m_damage.ChangeValue(m_damageAmplify);
}

bool DamageBuff::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	DamageBuff* temp = DYNAMIC(DamageBuff*, magic);
	if (nullptr == temp)
		return false;
	return m_damageAmplify == temp->m_damageAmplify;
}

bool DamageBuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic) 
		&& hasEqualParametres(magic);
}

bool DamageBuff::isBuff()const
{
	return true;
}

void DamageBuff::showData()const
{
	std::cout << "Damage add: " << m_damageAmplify << std::endl;
}

void DamageBuff::showFullInfo()const
{
	Magic::showData();
	showData();
}
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
ArmorBuff::ArmorBuff(std::string name, int manaCost,
	int duration, int armorAmplify)
	: Magic(name, manaCost, duration),
	m_armorAmplify(armorAmplify)
{

}

void ArmorBuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorBuff::uneffectUnit(Unit& unit)const
{
	unit.m_armor.ChangeValue(-m_armorAmplify);
}

MagicPtr ArmorBuff::clone()const
{
	return MagicPtr(new ArmorBuff(m_name, m_manaCost, m_durationmeter, m_armorAmplify));
}

void ArmorBuff::putOn(Unit& unit)const
{
	unit.m_armor.ChangeValue(m_armorAmplify);
}

bool ArmorBuff::isBuff()const
{
	return true;
}

bool ArmorBuff::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	ArmorBuff* temp = DYNAMIC(ArmorBuff*, magic);
	if (nullptr == temp)
		return false;
	return m_armorAmplify == temp->m_armorAmplify;
}

bool ArmorBuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic) 
		&& hasEqualParametres(magic);
}

void ArmorBuff::showData()const
{
	std::cout << "Armor add: " << m_armorAmplify << std::endl;
}

void ArmorBuff::showFullInfo()const
{
	Magic::showData();
	showData();
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
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
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
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