#include "../../Unit/Unit.h"

#include "CorruptionMagic.h"

CorruptionMagic::CorruptionMagic(std::string name, const Timer& timer,
	int armorReduce, PosibilityCounter propability)
	: Magic(name, ZERO_MANA_COST, timer),
	ArmorDebuffMagic(name, ZERO_MANA_COST, timer, armorReduce), 
	m_posibility(propability)
{

}

void CorruptionMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
		ArmorDebuffMagic::effectUnit(unit);
}

void CorruptionMagic::uneffectUnit(Unit& unit)const
{
	ArmorDebuffMagic::uneffectUnit(unit);
}

MagicPtr CorruptionMagic::clone()const
{
	return MagicPtr(new CorruptionMagic(m_name, m_timer,
		m_armorReduce, m_posibility));
}

bool CorruptionMagic::isBuff()const
{
	return false;
}

bool CorruptionMagic::isEqual(const MagicPtr& magic)const
{
	return ArmorDebuffMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void CorruptionMagic::showFullInfo()const
{
	ArmorDebuffMagic::showData();
	showData();
}

bool CorruptionMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (!canCast<CorruptionMagic*>(magic))
		return NO;
	CorruptionMagic* temp = DYNAMIC(CorruptionMagic*, magic);
	return m_posibility == temp->m_posibility;
}

void CorruptionMagic::showData()const
{
	std::cout << "Posibility: " << 
		m_posibility.getPosibility() << std::endl;
}