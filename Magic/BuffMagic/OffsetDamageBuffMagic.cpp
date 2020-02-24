#include "OffsetDamageBuffMagic.h"

OffsetDamageBuffMagic::OffsetDamageBuffMagic(std::string name, int manaCost,
	Time time, int armorReduce, int damageAmplify)
	: ParamChangeMagic(name, manaCost, time,
		{ ParamChangeElemPtr(new ArmorReduceElem(armorReduce)),
		ParamChangeElemPtr(new DamageAmplifyElem(damageAmplify)) })
{

}

MagicPtr OffsetDamageBuffMagic::clone()const
{
	return MagicPtr(new OffsetDamageBuffMagic(m_name, m_manaCost,
		m_time, m_elemHolder));
}

bool OffsetDamageBuffMagic::isBuff()const
{
	return true;
}

bool OffsetDamageBuffMagic::isDispelable()const
{
	return true;
}

bool OffsetDamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<OffsetDamageBuffMagic*>(magic)
		&& ParamChangeMagic::isEqual(magic);
}