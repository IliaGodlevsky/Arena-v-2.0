#include "NotEnoughDamageState.h"
#include "../../Unit/Unit.h"

NotEnoughDamageState::NotEnoughDamageState(Unit* unit)
	: InnerUnitState(unit)
{

}

bool NotEnoughDamageState::canAttack()const
{
	return false;
}

bool NotEnoughDamageState::isExpired()const
{
	return m_unit->m_damage > 0;
}

void NotEnoughDamageState::showShortInfo()const
{
	std::cout << "<Disarmed> ";
}

StatePtr NotEnoughDamageState::clone()const
{
	return StatePtr(new NotEnoughDamageState());
}

int NotEnoughDamageState::getValue()const
{
	return 4;
}