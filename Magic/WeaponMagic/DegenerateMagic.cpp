#include "../../Unit/Unit.h"

#include "DegenerateMagic.h"

DegenerateMagic::DegenerateMagic(std::string name, Time time,
	int degeneration, PosibilityCounter posibility)
	: WeaponMagic(name, time,
		{ ParamChangeElemPtr(new HpRegenReduceElem(degeneration)) }, posibility)
{

}

DegenerateMagic::DegenerateMagic(std::string name, Time time,
	const ElementHolder& elements, PosibilityCounter propability)
	: WeaponMagic(name, time, elements, propability)
{

}

bool DegenerateMagic::isDispelable()const
{
	return true;
}

MagicPtr DegenerateMagic::clone()const
{
	return MagicPtr(new DegenerateMagic(m_name, m_time, 
		m_elemHolder, m_posibility));
}

bool DegenerateMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<DegenerateMagic*>(magic))
		return false;
	const auto temp = dCast<DegenerateMagic*>(magic);
	return FreeParamChangeMagic::isEqual(magic) &&
		m_posibility == temp->m_posibility;
}