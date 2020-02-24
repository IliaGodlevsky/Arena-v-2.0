#include "../../Unit/Unit.h"

#include "DamageDebuffMagic.h"

DamageDebuffMagic::DamageDebuffMagic(std::string name, int manaCost,
	Time time, int damageReduce)
	: ParamChangeMagic(name, manaCost, time,
		{ ParamChangeElemPtr(new DamageReduceElem(damageReduce)) })
{

}

MagicPtr DamageDebuffMagic::clone()const
{
	return MagicPtr(new DamageDebuffMagic(m_name, 
		m_manaCost, m_time, m_elemHolder));
}

bool DamageDebuffMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<DamageDebuffMagic*>(magic) &&
		ParamChangeMagic::isEqual(magic);
}

bool DamageDebuffMagic::isBuff()const
{
	return false;
}

bool DamageDebuffMagic::isDispelable()const
{
	return true;
}