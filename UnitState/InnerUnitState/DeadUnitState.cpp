#include "DeadUnitState.h"
#include "../../Unit/Unit.h"

DeadUnitState::DeadUnitState(Unit* unit)
	: InnerUnitState(unit)
{

}

bool DeadUnitState::canCast()const
{
	return false;
}

bool DeadUnitState::canAttack()const
{
	return false;
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