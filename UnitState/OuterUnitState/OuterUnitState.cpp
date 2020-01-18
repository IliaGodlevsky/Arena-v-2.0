#include "OuterUnitState.h"
#include "../../Arena/Arena.h"

OuterUnitState::OuterUnitState(const Timer& timer)
	: m_timer(timer)
{

}

void OuterUnitState::setStartTime(int round)
{
	m_timer.setStartTime(round);
}

int OuterUnitState::getDuration()const
{
	return m_timer.getDuration();
}

bool OuterUnitState::isExpired()const
{
	return m_timer.isExpired(Arena::getCurrentRound());
}
