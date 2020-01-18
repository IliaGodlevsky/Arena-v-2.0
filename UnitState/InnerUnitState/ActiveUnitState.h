#ifndef ACTIVE_UNIT_STATE_H_
#define ACTIVE_UNIT_STATE_H_

#include "InnerUnitState.h"

class ActiveUnitState : public InnerUnitState
{
public:
	ActiveUnitState() = default;
	ActiveUnitState(Unit* unit);
	UnitPtr chooseUnitToAttack(DecisionPtr decision,const Unit& decidingUnit,
		const Gladiators& units)const override;
	MagicPtr chooseMagicToCast(DecisionPtr decision,const Unit& decidingUnit,
		const Gladiators& units)const override;
	UnitPtr chooseUnitToCast(DecisionPtr decision,const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const override;
	bool isExpired()const;
	StatePtr clone()const;
private:
	enum { ACTIVE_STATE = 0 };
	int getValue()const override;
};

#endif