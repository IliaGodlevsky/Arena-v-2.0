#ifndef MUTED_UNIT_STATE_H_
#define MUTED_UNIT_STATE_H_

#include "OuterUnitState.h"

/* Under this state unit is 
not able to cast any magic */
class MutedUnitState : public OuterUnitState
{
public:
	MutedUnitState(const Timer& timer);
	MutedUnitState() = default;
	bool canCast()const;
	void showShortInfo()const;
	StatePtr clone()const;
private:
	enum { MUTED_UNIT_STATE = 1 };
	int getValue()const override;
};

#endif