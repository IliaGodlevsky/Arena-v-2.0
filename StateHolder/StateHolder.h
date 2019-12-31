#ifndef STATE_HOLDER_H_
#define STATE_HOLDER_H_

#include "../Globals/Globals.h"
#include "../UnitState/UnitState.h"
#include "../UnitState/ActiveUnitState.h"
#include "../ICompareable/ExpireableContainer.h"

class StateHolder : public ExpireableContainer<StatePtr>
{
public:
	StateHolder(DecisionPtr decision);
	void takeNew(const StatePtr& unitState) override;
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, 
		const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, 
		const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const;
	void takeOffExpired(int round) override;
	void showShortInfo()const override;
	~StateHolder();
private:
	DecisionPtr m_decision;
	std::unique_ptr<ActiveUnitState> m_activeState;
};

#endif