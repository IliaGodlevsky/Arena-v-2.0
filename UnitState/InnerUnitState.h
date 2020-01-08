#ifndef INNER_UNIT_STATE_H_
#define INNER_UNIT_STATE_H_

#include "UnitState.h"

class InnerUnitState : virtual public UnitState
{
public:
	InnerUnitState(Unit* unit);
	InnerUnitState() = default;
	virtual void setOwner(Unit* unit) final;
	virtual bool isExpired()const = 0;
protected:
	Unit* m_unit;
};
#endif