#include "Decision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"
#include "../Interface/Interface.h"

Decision::Decision()
{

}

void Decision::takeAlly(const UnitPtr& ally)
{
	m_allies.takeAlly(ally);
}

bool Decision::isSameUnit(const Unit& unit1, const Unit& unit2)const
{
	return &unit1 == &unit2 || 
		(m_allies.isAlly(unit1) && m_allies.isAlly(unit2));
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

bool Decision::isAlly(const UnitPtr& unit)const
{
	return m_allies.isAlly(*unit);
}