#include "Decision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"
#include "../Interface/Interface.h"

Decision::Decision()
{

}

bool Decision::isSameUnit(const Unit& unit1, const Unit& unit2)const
{
	return unit1.isAlly(unit2);
}

bool Decision::canCastBuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	IBuff* buff = DYNAMIC(IBuff*, magic);
	return buff->isBuff() && isSameUnit(caster, aim);
}
bool Decision::canCastDebuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	IBuff* buff = DYNAMIC(IBuff*, magic);
	return !buff->isBuff() && !isSameUnit(caster, aim);
}

bool Decision::isWrongSpellToCast(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return !canCastBuffOnUnit(caster, aim, magic) &&
		!canCastDebuffOnUnit(caster, aim, magic);
}