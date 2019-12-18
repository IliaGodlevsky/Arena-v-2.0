#include "../../Unit/Unit.h"

#include "CrushMagic.h"


CrushMagic::CrushMagic(std::string name, int damage,
	int propability)
	: WeaponMagic(name, ZERO_DURATION, propability), m_damage(damage)
{

}

void CrushMagic::effectUnit(Unit& unit)
{
	if (isCastChance())
		putOn(unit);
}

void CrushMagic::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr CrushMagic::clone()const
{
	return MagicPtr(new CrushMagic(m_name, m_damage, m_propability));
}

bool CrushMagic::isBuff()const
{
	return false;
}

void CrushMagic::putOn(Unit& unit)const
{
	unit.m_health = unit.m_health - m_damage;
}

bool CrushMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	CrushMagic* temp = DYNAMIC(CrushMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_damage == temp->m_damage;
}

bool CrushMagic::isEqual(const MagicPtr& magic)const
{
	return WeaponMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void CrushMagic::showFullInfo()const
{
	WeaponMagic::showData();
	showData();
}

void CrushMagic::showData()const
{
	std::cout << "Damage: " << m_damage << std::endl;
}