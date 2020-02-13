#include "../../Unit/Unit.h"

#include "DegenerateMagic.h"

DegenerateMagic::DegenerateMagic(std::string name, Time time,
	int degeneration, PosibilityCounter posibility)
	: FreeParamChangeMagic(name, time,
		{ ParamChangeElemPtr(new HpRegenReduceElem(degeneration)) }), 
	m_posibility(posibility)
{

}

DegenerateMagic::DegenerateMagic(std::string name, Time time,
	const ElementHolder& elements, PosibilityCounter propability)
	: FreeParamChangeMagic(name, time, elements), m_posibility(propability)
{

}

void DegenerateMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
		FreeParamChangeMagic::effectUnit(unit);
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
	DegenerateMagic* temp = DYNAMIC(DegenerateMagic*, magic);
	return FreeParamChangeMagic::isEqual(magic) &&
		m_posibility == temp->m_posibility;
}