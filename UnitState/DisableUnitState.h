#ifndef DISABLE_UNIT_STATE_H_
#define DISABLE_UNIT_STATE_H_

#include "NotEnoughDamageUnitState.h"
#include "NotEnoughManaUnitState.h"

class DisableUnitState
	: public NotEnoughDamageUnitState,
	public NotEnoughManaUnitState
{
public:
	DisableUnitState(Unit* unit);
	DisableUnitState() = default;
	bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit,
		const Gladiators& units)const override;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit,
		const Gladiators& units)const override;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const override;
	bool isExpired()const override;
	void showShortInfo()const override;
private:
	enum { DISABLE_UNIT_STATE = 6 };
	int getValue()const;
};

#endif
