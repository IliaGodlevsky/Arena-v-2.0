#ifndef OUTER_UNIT_STATE_H_
#define OUTER_UNIT_STATE_H_

#include "../UnitState.h"

/* A base class for all states, that unit gains
from outer world ( from magic, weapon and etc.)*/
class OuterUnitState : public UnitState
{
public:
	OuterUnitState() = default;
	OuterUnitState(const Timer& timer);
	virtual void setStartTime(int round)final;
	virtual int getDuration()const final;
	virtual bool isExpired()const;
	virtual ~OuterUnitState() = default;
protected:
	Timer m_timer;
};
#endif
