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
	return false;
}

bool StunUnitState::canAttack()const
{
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
	return true;
}

bool StunUnitState::canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const
{
	return true;
}

StatePtr StunUnitState::clone()const
{
	return StatePtr(new StunUnitState(m_timer));
}