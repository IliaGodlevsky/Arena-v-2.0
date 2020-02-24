#include "../../Unit/Unit.h"

#include "CorruptionMagic.h"

CorruptionMagic::CorruptionMagic(std::string name, Time time,
	int armorReduce, PosibilityCounter propability)
	: WeaponMagic(name, time, 
		{ ParamChangeElemPtr(new ArmorReduceElem(armorReduce)) }, propability)
{

}

CorruptionMagic::CorruptionMagic(std::string name, Time time,
	const ElementHolder& elements, PosibilityCounter propability)
	: WeaponMagic(name, time, elements, propability)
{

}

MagicPtr CorruptionMagic::clone()const
{
	return MagicPtr(new CorruptionMagic(m_name, m_time,
		m_elemHolder, m_posibility));
}

bool CorruptionMagic::isDispelable()const
{
	return true;
}

bool CorruptionMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<CorruptionMagic*>(magic) &&
		WeaponMagic::isEqual(magic);
}