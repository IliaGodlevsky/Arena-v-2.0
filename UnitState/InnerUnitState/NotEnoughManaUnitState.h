#ifndef NOT_ENOUGH_MANA_H_
#define NOT_ENOUGH_NAMA_H_

#include "InnerUnitState.h"

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
	enum { NOT_ENOUGH_MANA_STATE = 2 };
	int getValue()const override;
};

#endif