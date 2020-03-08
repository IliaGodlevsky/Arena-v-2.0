#include "ActiveUnitState.h"

#include "../../Magic/Magic.h"
#include "../../Decision/Decision.h"
#include "../../Unit/Unit.h"

ActiveUnitState::ActiveUnitState(Unit* unit)
	: InnerUnitState(unit)
{

}

bool ActiveUnitState::isExpired()const
{
	return m_unit->isDead();
}

int ActiveUnitState::getValue()const
{
	return -2;
}

StatePtr ActiveUnitState::clone()const
{
	return StatePtr(new ActiveUnitState());
}