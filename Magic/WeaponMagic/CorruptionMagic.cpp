#include "CorruptionMagic.h"
#include "../../Unit/Unit.h"

CorruptionMagic::CorruptionMagic(std::string name, int duration,
	int armorReduce, int propability)
	: WeaponMagic(name, duration, propability),
	m_armorReduce(armorReduce)
{

}

void CorruptionMagic::effectUnit(Unit& unit)
{
	if (isCastChance())
	{
		putOn(unit);
		Magic::effectUnit(unit);
	}
}

void CorruptionMagic::uneffectUnit(Unit& unit)const
{
	unit.m_armor.changeValue(m_armorReduce);
}

MagicPtr CorruptionMagic::clone()const
{
	return MagicPtr(new CorruptionMagic(m_name, m_timer,
		m_armorReduce, m_propability));
}

bool CorruptionMagic::isBuff()const
{
	return false;
}

bool CorruptionMagic::isEqual(const MagicPtr& magic)const
{
	return WeaponMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void CorruptionMagic::showFullInfo()const
{
	WeaponMagic::showData();
	showData();
}

bool CorruptionMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	CorruptionMagic* temp = DYNAMIC(CorruptionMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_armorReduce == temp->m_armorReduce;
}

void CorruptionMagic::showData()const
{
	std::cout << "Armor reduce: " << m_armorReduce << std::endl;
}

void CorruptionMagic::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(-m_armorReduce);
}