#include "ActiveUnitState.h"

#include "../Magic/Magic.h"
#include "../Decision/Decision.h"
#include "../Unit/Unit.h"

ActiveUnitState::ActiveUnitState()
	: UnitState()
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

bool ActiveUnitState::isExpired()const
{
	return false;
}

int ActiveUnitState::getValue()const
{
	return ACTIVE_STATE;
}