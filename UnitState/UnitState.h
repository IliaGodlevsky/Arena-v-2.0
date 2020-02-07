#ifndef STATE_H_
#define STATE_H_

#include "../Globals/Globals.h"
#include "../Weapon/Weapon.h"

class UnitState;
using StatePtr = std::shared_ptr<UnitState>;

/* The state of unit. Base class. States are responsible 
for unit's ability to attack and take attacks and ability
to cast magic and take magic from other units */
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
	virtual StatePtr clone()const = 0;
private:
	virtual int getValue()const = 0;
};
#endif