#ifndef STUN_UNIT_STATE_H_
#define STUN_UNIT_STATE_H_

#include "OuterUnitState.h"

class StunUnitState : public OuterUnitState
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
	enum { STUN_UNIT_STATE  = 3};
	int getValue()const override;
};

#endif