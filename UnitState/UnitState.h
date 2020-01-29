#ifndef STATE_H_
#define STATE_H_

#include "../Globals/Globals.h"
#include "../Timer/Timer.h"
#include "../Weapon/Weapon.h"

class UnitState;
using StatePtr = std::shared_ptr<UnitState>;

class UnitState
{
public:
	UnitState() = default;
	virtual bool canCast()const;
	virtual bool canAttack()const;
	virtual bool canTakeDamage(Unit& unit, int damage)const;
	virtual bool canTakeMagicEffect(Unit& unit, 
		Unit& caster, MagicPtr& magic)const;
	virtual ~UnitState() = default;
	virtual void showShortInfo()const;
	virtual bool operator <(const UnitState& unitState)const final;
	virtual bool operator >(const UnitState& unitState)const final;
	virtual bool isEqual(const StatePtr& unitState)const final;
	virtual bool isExpired()const = 0;
	virtual StatePtr clone()const = 0;
private:
	virtual int getValue()const = 0;

};
#endif