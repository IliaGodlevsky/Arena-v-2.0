#include "../../Unit/Unit.h"

#include "CorruptionMagic.h"

CorruptionMagic::CorruptionMagic(std::string name, Timer timer,
	ArmorReduceElem armorReduce, PosibilityCounter propability)
	: FreeParamChangeMagic(name, timer),
	m_armorReduce(armorReduce), m_posibility(propability)
{

}

void CorruptionMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
	{
		FreeParamChangeMagic::effectUnit(unit);
		m_armorReduce.effectUnit(unit);
	}
}

void CorruptionMagic::uneffectUnit(Unit& unit)
{
	m_armorReduce.effectUnit(unit);
}

MagicPtr CorruptionMagic::clone()const
{
	return MagicPtr(new CorruptionMagic(m_name, m_timer,
		m_armorReduce, m_posibility));
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
		&& m_posibility == temp->m_posibility
		&& m_armorReduce == temp->m_armorReduce;
}

void CorruptionMagic::showFullInfo()const
{
	FreeParamChangeMagic::showFullInfo();
}