#include "MutedUnitState.h"

#include "../Magic/Magic.h"

MutedUnitState::MutedUnitState(int duration)
	: UnitState(duration)
{

}

UnitPtr MutedUnitState::chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const
{
	return m_decision->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr MutedUnitState::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
{
	return nullptr;
}

UnitPtr MutedUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return nullptr;
}

MutedUnitState::StateValue MutedUnitState::getValue()const
{
	return UnitState::MUTED_STATE;
}