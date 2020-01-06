#include "../Unit/Unit.h"

#include "NotEnoughManaUnitState.h"

NotEnoughManaUnitState::NotEnoughManaUnitState(Unit* unit)
	:m_unit(unit), MutedUnitState(Timer(0))
{

}

bool NotEnoughManaUnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return MutedUnitState::castMagic(caster, unit, magic);
}

bool NotEnoughManaUnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return MutedUnitState::injureUnit(weapon, unit, damage);
}

UnitPtr NotEnoughManaUnitState::chooseUnitToAttack(const Unit& decidingUnit,
	const Gladiators& units)const
{
	return MutedUnitState::chooseUnitToAttack(decidingUnit, units);
}

MagicPtr NotEnoughManaUnitState::chooseMagicToCast(const Unit& decidingUnit,
	const Gladiators& units)const
{
	return MutedUnitState::chooseMagicToCast(decidingUnit, units);
}

UnitPtr NotEnoughManaUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return MutedUnitState::chooseUnitToCast(decidingUnit, magicToCast, units);
}

bool NotEnoughManaUnitState::isExpired(int round)const
{
	return m_unit->m_magicBook.canCastAnySpell();
}

UnitState::StateValue NotEnoughManaUnitState::getValue()const
{
	return UnitState::NOT_ENOGHT_MANA_STATE;
}

void NotEnoughManaUnitState::showShortInfo()const
{
	std::cout << "<Can't cast> ";
}

void NotEnoughManaUnitState::getOwner(Unit* unit)
{
	m_unit = unit;
}