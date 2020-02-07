#include "../../Unit/Unit.h"

#include "DegenerateMagic.h"

DegenerateMagic::DegenerateMagic(std::string name, Time time,
	HpRegenReduceElem degeneration, PosibilityCounter posibility)
	: FreeParamChangeMagic(name, time),
	m_regenReduce(degeneration),
	m_posibility(posibility)
{

}

void DegenerateMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
	{
		FreeParamChangeMagic::effectUnit(unit);
		m_regenReduce.effectUnit(unit);
	}
}

bool DegenerateMagic::isDispelable()const
{
	return true;
}

void DegenerateMagic::uneffectUnit(Unit& unit)
{
	m_regenReduce.uneffectUnit(unit);
}

MagicPtr DegenerateMagic::clone()const
{
	return MagicPtr(new DegenerateMagic(m_name, m_time, 
		m_regenReduce, m_posibility));
}

bool DegenerateMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<DegenerateMagic*>(magic))
		return false;
	DegenerateMagic* temp = DYNAMIC(DegenerateMagic*, magic);
	return FreeParamChangeMagic::isEqual(magic) &&
		m_posibility == temp->m_posibility
		&& m_regenReduce == temp->m_regenReduce;
}

void DegenerateMagic::showFullInfo()const
{
	FreeParamChangeMagic::showFullInfo();
}