#include "DisableUnitState.h"

#include "../Magic/Magic.h"

DisableUnitState::DisableUnitState(Unit* unit)
	:InnerUnitState(unit),
	NotEnoughManaUnitState(unit),
	NotEnoughDamageUnitState(unit)
{

}

bool DisableUnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return NotEnoughManaUnitState::castMagic(caster, unit, magic);
}

bool DisableUnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return NotEnoughDamageUnitState::injureUnit(weapon, unit, damage);
}

UnitPtr DisableUnitState::chooseUnitToAttack(const Unit& decidingUnit,
	const Gladiators& units)const
{
	return NotEnoughDamageUnitState::chooseUnitToAttack(decidingUnit, units);
}

MagicPtr DisableUnitState::chooseMagicToCast(const Unit& decidingUnit,
	const Gladiators& units)const
{
	return NotEnoughManaUnitState::chooseMagicToCast(decidingUnit, units);
}

UnitPtr DisableUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return NotEnoughManaUnitState::chooseUnitToCast(decidingUnit, magicToCast, units);
}

bool DisableUnitState::isExpired()const
{
	return NotEnoughDamageUnitState::isExpired()
		|| NotEnoughManaUnitState::isExpired();
}

int DisableUnitState::getValue()const
{
	return DISABLE_UNIT_STATE;
}

void DisableUnitState::showShortInfo()const
{
	return;
}