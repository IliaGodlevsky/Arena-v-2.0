#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/StunUnitState.h"
#include "../../Arena/Arena.h"

#include "StunMagic.h"

StunMagic::StunMagic(std::string name, const Timer& timer, PosibilityCounter propability)
	: Magic(name, ZERO_MANA_COST, timer),
	m_posibility(propability)
{

}

void StunMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
	{
		putOn(unit);
		Magic::effectUnit(unit);
	}
}

void StunMagic::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr StunMagic::clone()const
{
	return MagicPtr(new StunMagic(m_name,
		m_timer, m_posibility));
}

bool StunMagic::isBuff()const
{
	return false;
}

bool StunMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void StunMagic::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Duration: " << m_timer.getDuration() << std::endl;
	showData();
}

bool StunMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (!canCast<StunMagic*>(magic))
		return NO;
	return Magic::isEqual(magic);
}

void StunMagic::showData()const
{
	std::cout << "Stuns unit for " << m_timer.getDuration() << " rounds\n";
}

void StunMagic::putOn(Unit& unit)const
{
	unit.recieveNewState(StatePtr(new StunUnitState(
		Timer(m_timer.getDuration(), Arena::getCurrentRound()))));
}