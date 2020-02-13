#include "../../Unit/Unit.h"

#include "CorruptionMagic.h"

CorruptionMagic::CorruptionMagic(std::string name, Time time,
	int armorReduce, PosibilityCounter propability)
	: FreeParamChangeMagic(name, time, 
		{ ParamChangeElemPtr(new ArmorReduceElem(armorReduce)) }),
	 m_posibility(propability)
{

}

CorruptionMagic::CorruptionMagic(std::string name, Time time,
	const ElementHolder& elements, PosibilityCounter propability)
	: FreeParamChangeMagic(name, time, elements),
	m_posibility(propability)
{

}

void CorruptionMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
		FreeParamChangeMagic::effectUnit(unit);
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
	if (!canCast<CorruptionMagic*>(magic))
		return false;
	CorruptionMagic* temp = DYNAMIC(CorruptionMagic*, magic);
	return FreeParamChangeMagic::isEqual(magic)
		&& m_posibility == temp->m_posibility;
}