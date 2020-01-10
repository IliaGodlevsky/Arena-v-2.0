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
	UnitState(DecisionPtr decision);
	virtual bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	virtual bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	virtual UnitPtr chooseUnitToAttack(const Unit& decidingUnit, 
		const Gladiators& units)const = 0;
	virtual MagicPtr chooseMagicToCast(const Unit& decidingUnit, 
		const Gladiators& units)const = 0;
	virtual UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const = 0;
	virtual ~UnitState() = default;
public:
	virtual void setDecision(DecisionPtr decision) final;
	virtual void showShortInfo()const;
public:
	virtual bool operator <(const UnitState& unitState)const final;
	virtual bool operator >(const UnitState& unitState)const final;
	virtual bool isEqual(const StatePtr& unitState)const final;
	virtual bool isExpired()const = 0;
protected:
	DecisionPtr m_decision = nullptr;
private:
	virtual int getValue()const = 0;

};
#endif