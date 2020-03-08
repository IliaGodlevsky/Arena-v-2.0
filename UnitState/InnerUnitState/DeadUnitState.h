#ifndef DEAD_UNIT_STATE_H_
#define DEAD_UNIT_STATE_H_

#include "InnerUnitState.h"

/* When unit dies, it recieves this state
he can't attack, can't spell and take any 
damage and magic from other units. But this 
state will never expire*/
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
	int getValue()const override;
};
#endif
