#ifndef DEAD_UNIT_STATE_H_
#define DEAD_UNIT_STATE_H_

#include "InnerUnitState.h"

class DeadUnitState : public InnerUnitState
{
public:
	DeadUnitState(Unit* unit);
	DeadUnitState() = default;
	bool canCast()const;
	bool canAttack()const;
	bool isExpired()const override;
	void showShortInfo()const override;
	StatePtr clone()const;
private:
	enum { DEAD_UNIT_STATE = 5 };
	int getValue()const override;
};
#endif
