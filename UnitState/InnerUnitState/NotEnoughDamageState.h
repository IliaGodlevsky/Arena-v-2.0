#ifndef NOT_ENOUGH_DAMAGE_STATE_H_
#define NOT_ENOUGH_DAMAGE_STATE_H_

#include "InnerUnitState.h"

class NotEnoughDamageState : public InnerUnitState
{
public:
	NotEnoughDamageState() = default;
	NotEnoughDamageState(Unit* unit);
	bool canAttack()const override;
	bool isExpired()const override;
	void showShortInfo()const override;
	StatePtr clone()const;
private:
	enum { NOT_ENOUGH_DAMAGE_STATE = 4 };
	int getValue()const override;
};

#endif