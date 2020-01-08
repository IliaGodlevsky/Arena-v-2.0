#ifndef NOT_ENOUGH_DAMAGE_UNIT_H_
#define NOT_ENOUGH_DAMAGE_UNIT_H_

#include "InnerUnitState.h"

class NotEnoughDamageUnitState : virtual public InnerUnitState
{
public:
	NotEnoughDamageUnitState(Unit* unit);
	NotEnoughDamageUnitState() = default;
	bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit,
		const Gladiators& units)const override;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit,
		const Gladiators& units)const override;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const override;
	bool isExpired()const override;
	void showShortInfo()const;
private:
	enum { NOT_ENOUGH_DAMAGE_STATE = 5 };
	int getValue()const override;

};
#endif
