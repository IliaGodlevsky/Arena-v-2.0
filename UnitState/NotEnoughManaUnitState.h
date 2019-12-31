#ifndef NOT_ENOUGH_MANA_H_
#define NOT_ENOUGH_NAMA_H_

#include "MutedUnitState.h"

class NotEnoughManaUnitState : public MutedUnitState
{
public:
	NotEnoughManaUnitState(Unit* unit);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit,
		const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit,
		const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, 
		const Gladiators& units)const;
	bool isExpired(int round)const override;
	void showShortInfo()const override;
private:
	StateValue getValue()const override;
	Unit* m_unit;
};

#endif