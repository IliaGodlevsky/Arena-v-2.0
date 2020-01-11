#include "../Unit/Unit.h"

#include "NotEnoughManaUnitState.h"

NotEnoughManaUnitState::NotEnoughManaUnitState(Unit* unit)
	: InnerUnitState(unit)
{

}

bool NotEnoughManaUnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return false;
}

bool NotEnoughManaUnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return UnitState::injureUnit(weapon, unit, damage);
}

UnitPtr NotEnoughManaUnitState::chooseUnitToAttack(const Unit& decidingUnit,
	const Gladiators& units)const
{
	return m_decision->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr NotEnoughManaUnitState::chooseMagicToCast(const Unit& decidingUnit,
	const Gladiators& units)const
{
	return nullptr;
}

UnitPtr NotEnoughManaUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return nullptr;
}

bool NotEnoughManaUnitState::isExpired()const
{
	return m_unit->m_magicBook.canCastAnySpell();
}

int NotEnoughManaUnitState::getValue()const
{
	return NOT_ENOUGH_MANA_STATE;
}

void NotEnoughManaUnitState::showShortInfo()const
{
	std::cout << "<Mana lack> ";
}