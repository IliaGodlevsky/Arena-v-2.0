#include "Decision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"
#include "../Interface/Interface.h"

bool isWrongUnitToAttack(const Unit& decidingUnit, const Unit& unit)
{
	return unit.isAlly(decidingUnit) || unit.isDead();
}

bool canCastBuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)
{
	IBuff* buff = DYNAMIC(IBuff*, magic);
	return buff->isBuff() && caster.isAlly(aim) && !aim.isDead();
}

bool canCastDebuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)
{
	IBuff* buff = DYNAMIC(IBuff*, magic);
	return !buff->isBuff() && !isWrongUnitToAttack(caster, aim);
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