#include "MagicShield.h"
#include "../PossibilityCounter/PosibilityCounter.h"
#include "../Magic/Elements/HpReduceElem.h"
#include "../Unit/Unit.h"
#include "../Interface/Interface.h"
#include "../UnitState/InnerUnitState/DeadUnitState.h"
#include "../Decision/Decision.h"

MagicShield::MagicShield(std::string name, int armor, int reflectChance)
	: Shield(name, armor, reflectChance)
{

}

ShieldPtr MagicShield::clone()const
{
	return ShieldPtr(new MagicShield(m_name, m_armor.getArmor(), m_reflectChance));
}

bool MagicShield::takeDamage(Unit& unit, int damage)const
{
	return true;
}

bool MagicShield::takeMagicEffect(Unit& unit, Unit& caster,
	MagicPtr& magic)const
{
	if (isReflected() && !unit.isAlly(caster))
	{
		signal(Signals::WAIT_TIME, Signals::MAGIC_BLOCK);
		std::cout << "But magic was reflected\n";
		return false;
	}
	return Shield::takeMagicEffect(unit, caster, magic);
}