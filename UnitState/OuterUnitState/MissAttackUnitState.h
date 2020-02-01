#ifndef MISS_ATTACK_UNIT_STATE_H_
#define MISS_ATTACK_UNIT_STATE_H_

#include "OuterUnitState.h"
#include "../../PossibilityCounter/PosibilityCounter.h"

class MissAttackUnitState : public OuterUnitState
{
public:
	MissAttackUnitState() = default;
	MissAttackUnitState(Timer timer, PosibilityCounter missChance);
	bool canAttack()const override;
	void showShortInfo()const override;
	StatePtr clone()const override;
private:
	enum { MISS_ATTACK_UNIT_STATE = -1 };
	int getValue()const override;
	PosibilityCounter m_missChance;
};
#endif
