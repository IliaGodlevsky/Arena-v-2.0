#include "Decision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"
#include "../Interface/Interface.h"

Decision::Decision()
{

}

bool Decision::canCastBuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	IBuff* buff = DYNAMIC(IBuff*, magic);
	return buff->isBuff() && caster.isAlly(aim) && aim.isAlive();
}
bool Decision::canCastDebuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	IBuff* buff = DYNAMIC(IBuff*, magic);
	return !buff->isBuff() && !caster.isAlly(aim) && aim.isAlive();
}

bool Decision::isWrongSpellToCast(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return !canCastBuffOnUnit(caster, aim, magic) &&
		!canCastDebuffOnUnit(caster, aim, magic);
}