#include "ArmorAndDamageBuffMagic.h"

ArmorAndDamageBuffMagic::ArmorAndDamageBuffMagic(std::string name, int manaCost,
	Time time, int armorAmplify,
	int damageAmplify)
	: ParamChangeMagic(name, manaCost, time,
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
	if (!canCast<ArmorAndDamageBuffMagic*>(magic))
		return false;
	return ParamChangeMagic::isEqual(magic);
}