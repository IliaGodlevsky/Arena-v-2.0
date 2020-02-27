#include "../../Unit/Unit.h"

#include "DamageBuffMagic.h"

DamageBuffMagic::DamageBuffMagic(std::string name, int manaCost,
	Time time, int damageAmplify)
	: ParamChangeMagic(name, manaCost, time,
		{ ParamChangeElemPtr(new DamageAmplifyElem(damageAmplify)) })
{

}

MagicPtr DamageBuffMagic::clone()const
{
	return MagicPtr(new DamageBuffMagic(m_name, m_manaCost, m_time, m_elemHolder));
}

bool DamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<DamageBuffMagic*>(magic)
		&& ParamChangeMagic::isEqual(magic);
}

bool DamageBuffMagic::isBuff()const
{
	return true;
}

bool DamageBuffMagic::isDispelable()const
{
	return true;
}