#include "Decision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"

Decision::Decision()
{

}

bool Decision::isSameUnit(const Unit& unit1, const Unit& unit2)const
{
	return &unit1 == &unit2;
}

bool Decision::canCastBuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return magic->isBuff() && isSameUnit(caster, aim);
}
bool Decision::canCastDebuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return !magic->isBuff() && !isSameUnit(caster, aim);
}

bool Decision::isWrongSpellToCast(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return !canCastBuffOnUnit(caster, aim, magic) &&
		!canCastDebuffOnUnit(caster, aim, magic);
}