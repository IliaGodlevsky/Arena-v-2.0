#ifndef OUTER_UNIT_STATE_H_
#define OUTER_UNIT_STATE_H_

#include "../UnitState.h"
#include "../../Expiring/Expiring.h"

/* A base class for all states, that unit gains
from outer world ( from magic, weapon and etc.)*/
class OuterUnitState : public UnitState, public Expiring
{
public:
	OuterUnitState() = default;
	OuterUnitState(Time time);
	virtual ~OuterUnitState() = default;
};
#endif
