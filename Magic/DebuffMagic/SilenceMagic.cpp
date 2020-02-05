#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/OuterUnitState/MutedUnitState.h"
#include "../../Arena/Arena.h"

#include "SilenceMagic.h"

SilenceMagic::SilenceMagic(std::string name, int manaCost, Timer timer)
	: Magic(name), IManaCost(manaCost), m_timer(timer)
{

}

void SilenceMagic::effectUnit(Unit& unit)
{
	unit.recieveNewState(StatePtr(new MutedUnitState(
		Timer(m_timer.getDuration(), Arena::getCurrentRound()))));
}

MagicPtr SilenceMagic::clone()const
{
	return MagicPtr(new SilenceMagic(m_name, m_manaCost, m_timer));
}

bool SilenceMagic::isBuff()const
{
	return false;
}

bool SilenceMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<SilenceMagic*>(magic))
		return NO;
	SilenceMagic* temp = DYNAMIC(SilenceMagic*, magic);
	return Magic::isEqual(magic) &&
		m_manaCost == temp->m_manaCost
		&& m_timer == temp->m_timer;
}

void SilenceMagic::showFullInfo()const
{
	Magic::showFullInfo();
	std::cout << "Enemy can't cast magic for " 
		<< m_timer.getDuration() << " rounds\n";
}

void SilenceMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}