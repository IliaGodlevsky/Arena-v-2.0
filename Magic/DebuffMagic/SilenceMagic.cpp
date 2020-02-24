#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/OuterUnitState/MutedUnitState.h"
#include "../../Arena/Arena.h"

#include "SilenceMagic.h"

SilenceMagic::SilenceMagic(std::string name, int manaCost, int duration)
	: Magic(name), IManaCost(manaCost), m_duration(duration)
{

}

void SilenceMagic::effectUnit(Unit& unit)
{
	unit.recieveNewState(StatePtr(new MutedUnitState(
		{ m_duration, Arena::getCurrentRound() })));
}

MagicPtr SilenceMagic::clone()const
{
	return MagicPtr(new SilenceMagic(m_name, m_manaCost, m_duration));
}

bool SilenceMagic::isBuff()const
{
	return false;
}

bool SilenceMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<SilenceMagic*>(magic))
		return NO;
	const auto temp = dCast<SilenceMagic*>(magic);
	return Magic::isEqual(magic) &&
		m_manaCost == temp->m_manaCost
		&& m_duration == temp->m_duration;
}

void SilenceMagic::showFullInfo()const
{
	Magic::showFullInfo();
	std::cout << "Enemy can't cast magic for " 
		<< m_duration << " rounds\n";
}

void SilenceMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}