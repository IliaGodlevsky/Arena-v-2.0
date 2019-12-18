#ifndef ACTIVE_UNIT_STATE_H_
#define ACTIVE_UNIT_STATE_H_

#include "UnitState.h"

class ActiveUnitState : public UnitState
{
public:
	ActiveUnitState();
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const override;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const override;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const override;
private:
	StateValue getValue()const override;
};

#endif