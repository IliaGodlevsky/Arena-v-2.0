#ifndef STATE_H_
#define STATE_H_

#include "../Globals/Globals.h"
#include "../Timer/Timer.h"
#include "../Decision/Decision.h"

class UnitState;
using StatePtr = std::shared_ptr<UnitState>;

class UnitState
{
public:
	explicit UnitState(const Timer& timer);
	virtual UnitPtr chooseUnitToAttack(const Unit& decidingUnit, 
		const Gladiators& units)const = 0;
	virtual MagicPtr chooseMagicToCast(const Unit& decidingUnit, 
		const Gladiators& units)const = 0;
	virtual UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const = 0;
	virtual ~UnitState() = default;
public:
	virtual void setDecision(DecisionPtr decision) final;
	virtual void setStartTime(int round)final;
	virtual bool isExpired(int round)const;
	virtual void showShortInfo()const final;
public:
	virtual bool operator <(const UnitState& unitState)const final;
	virtual bool operator >(const UnitState& unitState)const final;
protected:
	Timer m_timer;
	DecisionPtr m_decision;
	enum StateValue { ALIVE_STATE, MUTED_STATE, STUNNED_STATE };
	// static std::vector<UnitState*> m_attackStates;
private:
	virtual StateValue getValue()const = 0;

};
#endif