#include "../Magic/Magic.h"

#include "StunUnitState.h"

StunUnitState::StunUnitState(const Timer& timer)
	: UnitState(timer)
{

}

bool StunUnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return false;
}

bool StunUnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return false;
}

UnitPtr StunUnitState::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return UnitState::chooseUnitToAttack(decidingUnit, units);
}

MagicPtr StunUnitState::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return UnitState::chooseMagicToCast(decidingUnit, units);
}

UnitPtr StunUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return UnitState::chooseUnitToCast(decidingUnit, magicToCast, units);
}

UnitState::StateValue StunUnitState::getValue()const
{
	return UnitState::STUNNED_STATE;
}

void StunUnitState::showShortInfo()const
{
	std::cout << "<Stun> ";
}