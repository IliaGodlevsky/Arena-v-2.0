#pragma once

#ifndef UNIT_STATE_H_
#define UNIT_STATE_H_

class Unit;

class UnitState
{
public:
	UnitState(Unit* unit);
	virtual UnitState* Clone() = 0;
protected:
	Unit* unit;
};

class UnitIsDead 
	: public UnitState
{
public:
	UnitIsDead(Unit* unit);
	virtual UnitIsDead* Clone()const;
};

class ActiveState : public UnitState
{
public:
	ActiveState(Unit* unit);
	ActiveState* Clone()const;
};

class UnableToAttack 
	: virtual public UnitState
{
public:
	virtual UnableToAttack* Clone()const;
};

class UnableToSpell 
	: virtual public UnitState
{
public:
	virtual UnableToSpell* Clone()const;
};

class IsStunned 
	: public UnableToAttack, 
	public UnableToSpell
{
public:
	IsStunned* Clone()const;
};


#endif