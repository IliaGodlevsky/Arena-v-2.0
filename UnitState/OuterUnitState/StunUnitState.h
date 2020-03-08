#ifndef STUN_UNIT_STATE_H_
#define STUN_UNIT_STATE_H_

#include "OuterUnitState.h"

/* Under this state unit can't attack and cast magic
and takes all damage and magic in spite of shield */
class StunUnitState : public OuterUnitState
{
public:
	StunUnitState() = default;
	StunUnitState(Time time);
	bool canCast()const;
	bool canAttack()const;
	bool canTakeDamage(Unit& unit, int damage) const override;
	bool canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic) const override;
	void showShortInfo()const;
	StatePtr clone()const;
private:
	int getValue()const override;
};

#endif