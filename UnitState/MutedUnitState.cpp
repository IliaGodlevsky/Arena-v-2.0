#include "MutedUnitState.h"

#include "../Magic/Magic.h"

MutedUnitState::MutedUnitState(const Timer& timer)
	: OuterUnitState(timer)
{

}

bool MutedUnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return false;
}

bool MutedUnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return UnitState::injureUnit(weapon, unit, damage);
}

UnitPtr MutedUnitState::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return m_decision->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr MutedUnitState::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return nullptr;
}

UnitPtr MutedUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return nullptr;
}

int MutedUnitState::getValue()const
{
	return MUTED_UNIT_STATE;
}

void MutedUnitState::showShortInfo()const
{
	std::cout << "<Muted> ";
}