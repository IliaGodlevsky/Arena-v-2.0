#include "NotEnoughManaUnitState.h"
#include "../../Decision/Decision.h"
#include "../../Unit/Unit.h"

NotEnoughManaUnitState::NotEnoughManaUnitState(Unit* unit)
	: InnerUnitState(unit)
{

}

bool NotEnoughManaUnitState::canCast()const
{
	return false;
}

bool NotEnoughManaUnitState::isExpired()const
{
	return m_unit->m_magicBook.canCastAnySpell();
}

int NotEnoughManaUnitState::getValue()const
{
	return 2;
}

void NotEnoughManaUnitState::showShortInfo()const
{
	std::cout << "<Mana lack> ";
}

StatePtr NotEnoughManaUnitState::clone()const
{
	return StatePtr(new NotEnoughManaUnitState());
}