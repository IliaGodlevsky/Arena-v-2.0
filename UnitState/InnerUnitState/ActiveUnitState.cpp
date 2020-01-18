#include "ActiveUnitState.h"

#include "../../Magic/Magic.h"
#include "../../Decision/Decision.h"
#include "../../Unit/Unit.h"

ActiveUnitState::ActiveUnitState(Unit* unit)
	: InnerUnitState(unit)
{

}

UnitPtr ActiveUnitState::chooseUnitToAttack(DecisionPtr decision,const Unit& decidingUnit,
	const Gladiators& units)const
{
	return decision->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr ActiveUnitState::chooseMagicToCast(DecisionPtr decision,const Unit& decidingUnit,
	const Gladiators& units)const
{
	return decision->chooseMagicToCast(decidingUnit, units);
}

UnitPtr ActiveUnitState::chooseUnitToCast(DecisionPtr decision, const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return decision->chooseUnitToCast(decidingUnit, magicToCast, units);
}

bool ActiveUnitState::isExpired()const
{
	return !m_unit->isAlive();
}

int ActiveUnitState::getValue()const
{
	return ACTIVE_STATE;
}

StatePtr ActiveUnitState::clone()const
{
	return StatePtr(new ActiveUnitState());
}