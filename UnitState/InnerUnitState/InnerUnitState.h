#ifndef INNER_UNIT_STATE_H_
#define INNER_UNIT_STATE_H_

#include "../UnitState.h"
#include "../../Globals/Globals.h"
#include "../../Interface/Interface.h"

/* A base class for all states, 
that unit gains from itself*/
class InnerUnitState : public UnitState, 
	public IExpirable
{
public:
	InnerUnitState(Unit* unit);
	InnerUnitState() = default;
	virtual void setOwner(Unit* unit) final;
protected:
	Unit* m_unit;
};
#endif