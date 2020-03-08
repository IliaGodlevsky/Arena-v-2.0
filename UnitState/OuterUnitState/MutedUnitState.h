#ifndef MUTED_UNIT_STATE_H_
#define MUTED_UNIT_STATE_H_

#include "OuterUnitState.h"

/* Under this state unit is 
not able to cast any magic */
class MutedUnitState : public OuterUnitState
{
public:
	MutedUnitState(Time time);
	MutedUnitState() = default;
	bool canCast()const;
	void showShortInfo()const;
	StatePtr clone()const;
private:
	int getValue()const override;
};

#endif