#ifndef STUN_UNIT_STATE_H_
#define STUN_UNIT_STATE_H_

#include "OuterUnitState.h"

class StunUnitState : public OuterUnitState
{
public:
	StunUnitState() = default;
	StunUnitState(const Timer& timer);
	bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	bool takeDamage(Unit& unit, int damage) override;
	bool takeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic) override;
	UnitPtr chooseUnitToAttack(DecisionPtr decision, const Unit& decidingUnit,
		const Gladiators& units)const;
	MagicPtr chooseMagicToCast(DecisionPtr decision, const Unit& decidingUnit,
		const Gladiators& units)const;
	UnitPtr chooseUnitToCast(DecisionPtr decision, const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const;
	void showShortInfo()const;
	StatePtr clone()const;
private:
	enum { STUN_UNIT_STATE  = 3};
	int getValue()const override;
};

#endif