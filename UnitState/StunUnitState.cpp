#include "../Magic/Magic.h"

#include "StunUnitState.h"

StunUnitState::StunUnitState(int duration)
	: UnitState(duration)
{

}


UnitPtr StunUnitState::chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const
{
	return UnitState::chooseUnitToAttack(decidingUnit, units);
}

MagicPtr StunUnitState::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
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