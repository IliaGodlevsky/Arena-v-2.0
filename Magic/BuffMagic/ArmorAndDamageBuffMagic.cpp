#include "ArmorAndDamageBuffMagic.h"

ArmorAndDamageBuffMagic::ArmorAndDamageBuffMagic(std::string name, int manaCost,
	Time time, int armorAmplify,
	int damageAmplify)
	: UnitParametresChangeMagic(name, manaCost, time,
		{ ParamChangeElemPtr(new ArmorAmplifyElem(armorAmplify)),
			ParamChangeElemPtr(new DamageAmplifyElem(damageAmplify)) })
{

}

MagicPtr ArmorAndDamageBuffMagic::clone()const
{
	return MagicPtr(new ArmorAndDamageBuffMagic(m_name,
		m_manaCost, m_time, m_elemHolder));
}

bool ArmorAndDamageBuffMagic::isBuff()const
{
	return true;
}

bool ArmorAndDamageBuffMagic::isDispelable()const
{
	return true;
}

bool ArmorAndDamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<ArmorAndDamageBuffMagic*>(magic) &&
		UnitParametresChangeMagic::isEqual(magic);
}