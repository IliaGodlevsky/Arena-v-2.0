#ifndef NOT_ENOUGH_MANA_H_
#define NOT_ENOUGH_NAMA_H_

#include "InnerUnitState.h"

class NotEnoughManaUnitState : public InnerUnitState
{
public:
	NotEnoughManaUnitState(Unit* unit);
	NotEnoughManaUnitState() = default;
	bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit,
		const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit,
		const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, 
		const Gladiators& units)const;
	bool isExpired()const override;
	void showShortInfo()const override;
private:
	enum { NOT_ENOUGH_MANA_STATE = 4 };
	int getValue()const override;
};

#endif