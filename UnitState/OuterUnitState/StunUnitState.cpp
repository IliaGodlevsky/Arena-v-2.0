#include "../../Magic/Magic.h"

#include "StunUnitState.h"
#include "../../Arena/Arena.h"
#include "../../Unit/Unit.h"
#include "../InnerUnitState/DeadUnitState.h"

StunUnitState::StunUnitState(const Timer& timer)
	: OuterUnitState(timer)
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
	std::cout << "<Stun: " << m_timer.getStartTime()
		+ m_timer.getDuration() - Arena::getCurrentRound() << "> ";
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
	return StatePtr(new StunUnitState(m_timer));
}