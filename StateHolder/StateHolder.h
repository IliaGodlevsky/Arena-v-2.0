#pragma once

#ifndef STATE_HOLDER_H_
#define STATE_HOLDER_H_

#include "Globals.h"
#include "State.h"

class StateHolder
{
public:
	StateHolder(DecisionPtr decision);
	void recieveNewState(StatePtr unitState);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const;
	void takeOfExpiredStates(int round);
	void expireAllStates();
	void showShortInfo()const;
	~StateHolder();
private:
	DecisionPtr m_decision;
	std::vector<StatePtr> m_unitStates;
	std::unique_ptr<ActiveState> m_activeState;
};

#endif