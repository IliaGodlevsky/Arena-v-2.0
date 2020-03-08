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
	return false;
}

void DeadUnitState::showShortInfo()const
{
	std::cout << "<Dead> ";
}

int DeadUnitState::getValue()const
{
	return 5;
}

StatePtr DeadUnitState::clone()const
{
	return StatePtr(new DeadUnitState());
}