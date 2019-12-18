#pragma once

#ifndef STUN_UNIT_STATE_H_
#define STUN_UNIT_STATE_H_

#include "UnitState.h"

class StunUnitState : public UnitState
{
public:
	StunUnitState(int duration);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const;
private:
	StateValue getValue()const override;
};

#endif