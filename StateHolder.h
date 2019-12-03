#pragma once

#ifndef STATE_HOLDER_H_
#define STATE_HOLDER_H_

#include "Globals.h"
#include "State.h"
class StateHolder
{
public:
	StateHolder();
	void RecieveNewState(UnitState* state);
	Unit* ChooseUnitToAttack(const Unit& deciding_unit)const;
	MagicPtr ChooseMagicToCast(const Unit& deciding_unit)const;
	Unit* ChooseUnitToCast(const Unit& deciding_unit,
		const MagicPtr& magic_to_spell)const;
	void TakeOfExpired(int round);
	void ExpireAllStates();
	~StateHolder();
private:
	std::vector<UnitState*> unit_states;
	ActiveState* active_state;
};

#endif