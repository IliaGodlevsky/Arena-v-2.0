#ifndef STUN_UNIT_STATE_H_
#define STUN_UNIT_STATE_H_

#include "UnitState.h"

class StunUnitState : public UnitState
{
public:
	StunUnitState(const Timer& timer);
	bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, 
		const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, 
		const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const;
	void showShortInfo()const;
private:
	StateValue getValue()const override;
};

#endif