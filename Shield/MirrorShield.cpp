#include "../Shield/MirrorShield.h"
#include "../PossibilityCounter/PosibilityCounter.h"
#include "../UnitState/InnerUnitState/NotEnoughDamageState.h"
#include "../Magic/AttackMagic/AttackMagic.h"
#include "../Interface/Interface.h"
#include "../Unit/Unit.h"

MirrorShield::MirrorShield(std::string name, int armor, int reflectChance)
	: MagicShield(name, armor, reflectChance)
{

}

bool MirrorShield::takeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const
{
	const bool isEffected = MagicShield::takeMagicEffect(unit, caster, magic);
	if (!isEffected)
	{
		const auto temp = dCast<AttackMagic*>(magic);
		if (nullptr == temp)
		{
			signal(Signals::WAIT_TIME, Signals::MAGIC_REFLECT);
			caster.takeMagicEffect(caster, magic);
			std::cout << "back to ";
			std::cout << caster.getName() << std::endl;
		}
	}
	return isEffected;
}

ShieldPtr MirrorShield::clone()const
{
	return ShieldPtr(new MirrorShield(m_name, m_armor.getArmor(), m_reflectChance));
}