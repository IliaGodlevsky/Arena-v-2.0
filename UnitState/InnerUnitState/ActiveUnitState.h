#ifndef ACTIVE_UNIT_STATE_H_
#define ACTIVE_UNIT_STATE_H_

#include "InnerUnitState.h"

/* Default unit state. */
class ActiveUnitState : public InnerUnitState
{
public:
	ActiveUnitState() = default;
	ActiveUnitState(Unit* unit);
	bool isExpired()const;
	StatePtr clone()const;
private:
	enum { ACTIVE_STATE = -2 };
	int getValue()const override;
};

#endif