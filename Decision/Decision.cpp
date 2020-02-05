#include "Decision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"
#include "../Interface/Interface.h"

bool isWrongUnitToAttack(const Unit& decidingUnit, const UnitPtr& unit)
{
	return unit->isAlly(decidingUnit) || !unit->isAlive();
}

bool canCastBuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)
{
	IBuff* buff = DYNAMIC(IBuff*, magic);
	return buff->isBuff() && caster.isAlly(aim) && aim.isAlive();
}

bool canCastDebuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)
{
	IBuff* buff = DYNAMIC(IBuff*, magic);
	return !buff->isBuff() && !caster.isAlly(aim) && aim.isAlive();
}

bool isWrongSpellToCast(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)
{
	return !canCastBuffOnUnit(caster, aim, magic) &&
		!canCastDebuffOnUnit(caster, aim, magic);
}

Decision::Decision()
{

}