#include "../../Unit/Unit.h"
#include "MissAttackUnitState.h"

MissAttackUnitState::MissAttackUnitState(Timer timer,
	PosibilityCounter missChance) : OuterUnitState(timer),
	m_missChance(missChance)
{

}

bool MissAttackUnitState::canAttack()const
{
	return !m_missChance;
}

void MissAttackUnitState::showShortInfo()const
{
	std::cout << "<See double: " << m_timer.getStartTime()
		+ m_timer.getDuration() - Arena::getCurrentRound() << "> ";
}

StatePtr MissAttackUnitState::clone()const
{
	return StatePtr(new MissAttackUnitState(m_timer, m_missChance));
}

int MissAttackUnitState::getValue()const
{
	return MISS_ATTACK_UNIT_STATE;
}