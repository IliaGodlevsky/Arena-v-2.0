#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/StunUnitState.h"
#include "../../Arena/Arena.h"

#include "StunMagic.h"

StunMagic::StunMagic(std::string name, Timer timer, PosibilityCounter propability)
	: Magic(name),
	m_posibility(propability), m_timer(timer)
{

}

void StunMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
	{
		unit.recieveNewState(StatePtr(new StunUnitState(
			Timer(m_timer.getDuration(), Arena::getCurrentRound()))));
	}
}

void StunMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << "> ";
}

MagicPtr StunMagic::clone()const
{
	return MagicPtr(new StunMagic(m_name,
		m_timer, m_posibility));
}

bool StunMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<StunMagic*>(magic))
		return false;
	return Magic::isEqual(magic);
}

void StunMagic::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Duration: " << m_timer.getDuration() << std::endl;
	std::cout << "Stuns unit for " << m_timer.getDuration() << " rounds\n";
}