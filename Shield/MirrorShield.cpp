#include "../Shield/MirrorShield.h"
#include "../PossibilityCounter/PosibilityCounter.h"
#include "../Magic/AttackMagic/AttackMagic.h"
#include "../Interface/Interface.h"
#include "../Unit/Unit.h"

MirrorShield::MirrorShield(std::string name, int armor, int reflectChance)
	: MagicShield(name, armor, reflectChance)
{

}

bool MirrorShield::takeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const
{
	if (PosibilityCounter(m_reflectChance) && !unit.isAlly(caster))
	{
		AttackMagic* temp = DYNAMIC(AttackMagic*, magic);
		commentator.writeMessage("But magic was reflected");
		if (nullptr == temp)
		{
			magic->effectUnit(caster);
			commentator.writeMessage(" back to ", caster.getName());
		}
		commentator.writeMessage("\n");
		return false;
	}
	return Shield::takeMagicEffect(unit, caster, magic);
}

ShieldPtr MirrorShield::clone()const
{
	return ShieldPtr(new MirrorShield(m_name, m_armor.getArmor(), m_reflectChance));
}