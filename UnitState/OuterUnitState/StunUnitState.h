#ifndef STUN_UNIT_STATE_H_
#define STUN_UNIT_STATE_H_

#include "OuterUnitState.h"

class StunUnitState : public OuterUnitState
{
public:
	StunUnitState() = default;
	StunUnitState(const Timer& timer);
	bool canCast()const;
	bool canAttack()const;
	bool canTakeDamage(Unit& unit, int damage) const override;
	bool canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic) const override;
	void showShortInfo()const;
	StatePtr clone()const;
private:
	enum { STUN_UNIT_STATE  = 3};
	int getValue()const override;
};

#endif