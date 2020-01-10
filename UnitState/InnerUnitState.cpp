#include "InnerUnitState.h"
#include "../Unit/Unit.h"
#include "../Magic/Magic.h"

InnerUnitState::InnerUnitState(Unit* unit)
	: m_unit(unit)
{

}

void InnerUnitState::setOwner(Unit* unit)
{
	m_unit = unit;
}