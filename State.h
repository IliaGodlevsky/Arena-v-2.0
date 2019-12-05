#pragma once

#ifndef STATE_H_
#define STATE_H_

#include "Globals.h"
#include "Durationmeter.h"

class UnitState
{
public:
	UnitState(int duration);
	virtual UnitPtr chooseUnitToAttack(const Unit& decidingUnit)const = 0;
	virtual MagicPtr chooseMagicToCast(const Unit& decidingUnit)const = 0;
	virtual UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast)const = 0;
	virtual ~UnitState() = default;
public:
	virtual void setDecision(std::shared_ptr<Decision> decision) final;
	virtual void setStartTime(int round)final;
	virtual bool isExpired(int round)const final;
public:
	virtual bool operator <(const UnitState& unitState)const final;
	virtual bool operator >(const UnitState& unitState)const final;
protected:
	Durationmeter m_durationmeter;
	std::shared_ptr<Decision> m_decision_ptr;
	enum StateValue { ALIVE_STATE, MUTED_STATE, STUNNED_STATE };
	// static std::vector<UnitState*> m_attackStates;
private:
	virtual StateValue getValue()const = 0;

};

class ActiveState : public UnitState
{
public:
	ActiveState();
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit)const override;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit)const override;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast)const override;
private:
	StateValue getValue()const override;
};

class MutedState : public UnitState
{
public:
	MutedState(int duration);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit)const override;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit)const override;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast)const override;
private:
	StateValue getValue()const override;
};

class StunState : public UnitState
{
public:
	StunState(int duration);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast)const;
private:
	StateValue getValue()const override;
};


#endif