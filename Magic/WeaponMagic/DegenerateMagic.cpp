#include "DegenerateMagic.h"
#include "../../Unit/Unit.h"

DegenerateMagic::DegenerateMagic(std::string name, int duration,
	int degeneration, int propability)
	: WeaponMagic(name, duration, propability),
	m_degeneration(degeneration)
{

}

void DegenerateMagic::effectUnit(Unit& unit)
{
	if (isCastChance())
	{
		putOn(unit);
		Magic::effectUnit(unit);
	}
}

void DegenerateMagic::uneffectUnit(Unit& unit)const
{
	unit.m_health.changeRegeneration(m_degeneration);
}

MagicPtr DegenerateMagic::clone()const
{
	return MagicPtr(new DegenerateMagic(m_name, m_timer, m_degeneration, m_propability));
}

bool DegenerateMagic::isBuff()const
{
	return false;
}

void DegenerateMagic::putOn(Unit& unit)const
{
	unit.m_health.changeRegeneration(-m_degeneration);
}

bool DegenerateMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	DegenerateMagic* temp = DYNAMIC(DegenerateMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_degeneration == temp->m_degeneration;
}

bool DegenerateMagic::isEqual(const MagicPtr& magic)const
{
	return WeaponMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void DegenerateMagic::showFullInfo()const
{
	WeaponMagic::showData();
	showData();
}

void DegenerateMagic::showData()const
{
	std::cout << "Deals " << m_degeneration << " per round\n";
}