#ifndef INNER_UNIT_STATE_H_
#define INNER_UNIT_STATE_H_

#include "../UnitState.h"
#include "../../Globals/Globals.h"

/* A base class for all states, 
that unit gains from itself*/
class InnerUnitState : public UnitState
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