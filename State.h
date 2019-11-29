#pragma once

#ifndef STATE_H_
#define STATE_H_

#include "Globals.h"


class UnitState
{
public:
	UnitState(int duration);
	virtual Unit* ChooseUnitToAttack(const Unit& deciding_unit)const = 0;
	virtual MagicPtr ChooseMagicToCast(const Unit& deciding_unit)const = 0;
	virtual Unit* ChooseUnitToCast(const Unit& deciding_unit,
		const MagicPtr& magic_to_spell)const = 0;
	virtual ~UnitState() = default;
public:
	virtual void RecieveDecision(Decision* decision) final;
	virtual void SetStartTime(int round)final;
	virtual bool IsExpired(int round)const final;
public:
	virtual bool operator <(const UnitState& state)const final;
	virtual bool operator>(const UnitState& state)const final;
protected:
	Durationmeter durationmeter;
	Decision* decision;
	enum StateValue { ALIVE_STATE, MUTED_STATE, STUNNED_STATE };
private:
	virtual StateValue Value()const = 0;

};

class ActiveState : public UnitState
{
public:
	ActiveState();
	Unit* ChooseUnitToAttack(const Unit& deciding_unit)const;
	MagicPtr ChooseMagicToCast(const Unit& deciding_unit)const;
	Unit* ChooseUnitToCast(const Unit& deciding_unit,
		const MagicPtr& magic_to_spell)const;
private:
	StateValue Value()const;
};

class MutedState : public UnitState
{
public:
	MutedState(int duration);
	Unit* ChooseUnitToAttack(const Unit& deciding_unit)const;
	MagicPtr ChooseMagicToCast(const Unit& deciding_unit)const;
	Unit* ChooseUnitToCast(const Unit& deciding_unit,
		const MagicPtr& magic_to_spell)const;
private:
	StateValue Value()const;
};

class StunState : public UnitState
{
public:
	StunState(int duration);
	Unit* ChooseUnitToAttack(const Unit& deciding_unit)const;
	MagicPtr ChooseMagicToCast(const Unit& deciding_unit)const;
	Unit* ChooseUnitToCast(const Unit& deciding_unit,
		const MagicPtr& magic_to_spell)const;
private:
	StateValue value()const;
};

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