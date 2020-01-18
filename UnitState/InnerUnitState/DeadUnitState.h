#ifndef DEAD_UNIT_STATE_H_
#define DEAD_UNIT_STATE_H_

#include "InnerUnitState.h"

class DeadUnitState : public InnerUnitState
{
public:
	DeadUnitState(Unit* unit);
	DeadUnitState() = default;
	bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	UnitPtr chooseUnitToAttack(DecisionPtr decision,const Unit& decidingUnit,
		const Gladiators& units)const;
	MagicPtr chooseMagicToCast(DecisionPtr decision,const Unit& decidingUnit,
		const Gladiators& units)const;
	UnitPtr chooseUnitToCast(DecisionPtr decision,
		const Unit& decidingUnit,
		const MagicPtr& magicToCast,
		const Gladiators& units)const;
	bool isExpired()const override;
	void showShortInfo()const override;
	StatePtr clone()const;
private:
	enum { DEAD_UNIT_STATE = 4 };
	int getValue()const override;
};
#endif
