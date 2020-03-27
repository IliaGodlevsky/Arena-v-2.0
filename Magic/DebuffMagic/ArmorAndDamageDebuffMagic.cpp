#include "ArmorAndDamageDebuffMagic.h"

ArmorAndDamageDebuffMagic::ArmorAndDamageDebuffMagic(std::string name, int manaCost,
	Time time, int armorReduce, int damageReduce)
	: UnitParametresChangeMagic(name, manaCost, time, 
		{ParamChangeElemPtr(new ArmorReduceElem(armorReduce)),
		ParamChangeElemPtr(new DamageReduceElem(damageReduce))})
{

}

MagicPtr ArmorAndDamageDebuffMagic::clone()const
{
	return MagicPtr(new ArmorAndDamageDebuffMagic(m_name,
		m_manaCost, m_time, m_elemHolder));
}

bool ArmorAndDamageDebuffMagic::isBuff()const
{
	return false;
}

bool ArmorAndDamageDebuffMagic::isDispelable()const
{
	return true;
}

bool ArmorAndDamageDebuffMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<ArmorAndDamageDebuffMagic*>(magic) 
		&& UnitParametresChangeMagic::isEqual(magic);
}