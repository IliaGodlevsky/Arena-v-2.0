#ifndef NOT_ENOUGH_MANA_H_
#define NOT_ENOUGH_NAMA_H_

#include "InnerUnitState.h"

/* When unit doesn't have enough mana 
to cast any magic it will recieve this state*/
class NotEnoughManaUnitState : public InnerUnitState
{
public:
	NotEnoughManaUnitState(Unit* unit);
	NotEnoughManaUnitState() = default;
	bool canCast()const;
	bool isExpired()const override;
	void showShortInfo()const override;
	StatePtr clone()const;
private:
	int getValue()const override;
};

#endif