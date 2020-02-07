#include "../../Unit/Unit.h"
#include "MissAttackUnitState.h"

MissAttackUnitState::MissAttackUnitState(Time time,
	PosibilityCounter missChance) : OuterUnitState(time), 
	m_missChance(missChance)
{

}

bool MissAttackUnitState::canAttack()const
{
	return !m_missChance;
}

void MissAttackUnitState::showShortInfo()const
{
	std::cout << "<See double: " << getDurationRemained() << "> ";
}

StatePtr MissAttackUnitState::clone()const
{
	return StatePtr(new MissAttackUnitState(m_time, m_missChance));
}

int MissAttackUnitState::getValue()const
{
	return MISS_ATTACK_UNIT_STATE;
}