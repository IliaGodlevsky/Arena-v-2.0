#include "../../Unit/Unit.h"

#include "DegenerateMagic.h"

DegenerateMagic::DegenerateMagic(std::string name, const Timer& timer,
	int degeneration, PosibilityCounter posibility)
	: Magic(name, ZERO_MANA_COST, timer),
	PoisonMagic(name, ZERO_MANA_COST, timer, degeneration),
	m_posibility(posibility)
{

}

void DegenerateMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
		PoisonMagic::effectUnit(unit);
}

void DegenerateMagic::uneffectUnit(Unit& unit)const
{
	PoisonMagic::uneffectUnit(unit);
}

MagicPtr DegenerateMagic::clone()const
{
	return MagicPtr(new DegenerateMagic(m_name, m_timer, m_regenReduce, m_posibility));
}

bool DegenerateMagic::isBuff()const
{
	return false;
}

bool DegenerateMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (!canCast<DegenerateMagic*>(magic))
		return NO;
	DegenerateMagic* temp = DYNAMIC(DegenerateMagic*, magic);
	return m_posibility == temp->m_posibility;
}

bool DegenerateMagic::isEqual(const MagicPtr& magic)const
{
	return PoisonMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void DegenerateMagic::showFullInfo()const
{
	PoisonMagic::showData();
	showData();
}

void DegenerateMagic::showData()const
{
	std::cout << "Posibility: " <<
		m_posibility.getPosibility() << std::endl;
}