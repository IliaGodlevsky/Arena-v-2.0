#include "DeadUnitState.h"
#include "../../Unit/Unit.h"

DeadUnitState::DeadUnitState(Unit* unit)
	: InnerUnitState(unit)
{

}

bool DeadUnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return false;
}

bool DeadUnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return false;
}

UnitPtr DeadUnitState::chooseUnitToAttack(DecisionPtr decision,const Unit& decidingUnit,
	const Gladiators& units)const
{
	return nullptr;
}

MagicPtr DeadUnitState::chooseMagicToCast(DecisionPtr decision,const Unit& decidingUnit,
	const Gladiators& units)const
{
	return nullptr;
}

UnitPtr DeadUnitState::chooseUnitToCast(DecisionPtr decision,const Unit& decidingUnit,
	const MagicPtr& magicToCast,
	const Gladiators& units)const
{
	return nullptr;
}

bool DeadUnitState::isExpired()const
{
	return m_unit->isAlive();
}

void DeadUnitState::showShortInfo()const
{
	std::cout << "<Dead> ";
}

int DeadUnitState::getValue()const
{
	return DEAD_UNIT_STATE;
}

StatePtr DeadUnitState::clone()const
{
	return StatePtr(new DeadUnitState());
}