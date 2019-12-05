#pragma once

#ifndef STATE_HOLDER_H_
#define STATE_HOLDER_H_

#include "Globals.h"
#include "State.h"

class StateHolder
{
public:
	StateHolder(std::shared_ptr<Decision> decision);
	void recieveNewState(std::shared_ptr<UnitState>& unitState);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast)const;
	void takeOfExpiredStates(int round);
	void expireAllStates();
	~StateHolder();
private:
	std::shared_ptr<Decision> m_decision;
	std::vector<std::shared_ptr<UnitState>> m_unitStates;
	std::unique_ptr<ActiveState> m_activeState;
};

#endif