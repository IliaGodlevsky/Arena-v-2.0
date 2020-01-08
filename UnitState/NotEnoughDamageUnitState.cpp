#include "../Unit/Unit.h"
#include "NotEnoughDamageUnitState.h"
#include "../Magic/Magic.h"

NotEnoughDamageUnitState::NotEnoughDamageUnitState(Unit* unit)
	: InnerUnitState(unit)
{

}

bool NotEnoughDamageUnitState::castMagic(Unit& caster, Unit& unit,
	MagicPtr& magic)
{
	return UnitState::castMagic(caster, unit, magic);
}

bool NotEnoughDamageUnitState::injureUnit(WeaponPtr& weapon, 
	Unit& unit, int damage)
{
	return false;
}

UnitPtr NotEnoughDamageUnitState::chooseUnitToAttack(const Unit& decidingUnit,
	const Gladiators& units)const
{
	return nullptr;
}

MagicPtr NotEnoughDamageUnitState::chooseMagicToCast(const Unit& decidingUnit,
	const Gladiators& units)const
{
	return m_decision->chooseMagicToCast(decidingUnit, units);
}

UnitPtr NotEnoughDamageUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return m_decision->chooseUnitToCast(decidingUnit, magicToCast, units);
}

bool NotEnoughDamageUnitState::isExpired()const
{
	return m_unit->m_damage + m_unit->m_weapon->getDamage() > 0;
}

int NotEnoughDamageUnitState::getValue()const
{
	return NOT_ENOUGH_DAMAGE_STATE;
}

void NotEnoughDamageUnitState::showShortInfo()const
{
	std::cout << "<Can't attack> ";
}