#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/OuterUnitState/StunUnitState.h"
#include "../../Arena/Arena.h"

#include "StunMagic.h"

StunMagic::StunMagic(std::string name, int duration, PosibilityCounter propability)
	: Magic(name), m_posibility(propability), m_duration(duration)
{

}

void StunMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
	{
		unit.recieveNewState(StatePtr(new StunUnitState(
			{ m_duration, Arena::getCurrentRound() })));
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
		m_duration, m_posibility));
}

bool StunMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<StunMagic*>(magic) &&
		Magic::isEqual(magic);
}

void StunMagic::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Stuns unit for " << m_duration << " rounds\n";
}