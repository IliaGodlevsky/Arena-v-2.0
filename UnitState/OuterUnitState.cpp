#include "OuterUnitState.h"

OuterUnitState::OuterUnitState(const Timer& timer)
	:m_timer(timer)
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

bool OuterUnitState::isExpired(int round)const
{
	return m_timer.isExpired(round);
}