#ifndef MUTED_UNIT_STATE_H_
#define MUTED_UNIT_STATE_H_

#include "OuterUnitState.h"

class MutedUnitState : public OuterUnitState
{
public:
	MutedUnitState(const Timer& timer);
	MutedUnitState() = default;
	bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, 
		const Gladiators& units)const override;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, 
		const Gladiators& units)const override;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const override;
	void showShortInfo()const;
private:
	enum { MUTED_UNIT_STATE = 1 };
	int getValue()const override;
};

#endif