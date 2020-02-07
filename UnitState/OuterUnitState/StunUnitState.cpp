#include "../../Magic/Magic.h"

#include "StunUnitState.h"
#include "../../Unit/Unit.h"
#include "../InnerUnitState/DeadUnitState.h"

StunUnitState::StunUnitState(Time time)
	: OuterUnitState(time)
{

}

bool StunUnitState::canCast()const
{
	// unit is not able to cast any magic while being stunned
	return false;
}

bool StunUnitState::canAttack()const
{
	// unit is not able to attack while being stunned
	return false;
}

int StunUnitState::getValue()const
{
	return STUN_UNIT_STATE;
}

void StunUnitState::showShortInfo()const
{
	std::cout << "<Stun: " << getDurationRemained() << "> ";
}

bool StunUnitState::canTakeDamage(Unit& unit, int damage)const
{
	// unit will take any incoming damage and won't reflect it
	return true;
}

bool StunUnitState::canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const
{
	// unit will take any incoming magic and won't reflect int
	return true;
}

StatePtr StunUnitState::clone()const
{
	return StatePtr(new StunUnitState(m_time));
}