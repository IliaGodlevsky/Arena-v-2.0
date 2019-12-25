#include "ActiveUnitState.h"

#include "../Magic/Magic.h"

ActiveUnitState::ActiveUnitState()
	: UnitState(Timer(INT_MAX))
{

}

UnitPtr ActiveUnitState::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return m_decision->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr ActiveUnitState::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return m_decision->chooseMagicToCast(decidingUnit, units);
}

UnitPtr ActiveUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return m_decision->chooseUnitToCast(decidingUnit, magicToCast, units);
}

UnitState::StateValue ActiveUnitState::getValue()const
{
	return UnitState::ALIVE_STATE;
}