#include "MutedUnitState.h"

#include "../../Magic/Magic.h"
#include "../../Decision/Decision.h"
#include "../../Unit/Unit.h"

MutedUnitState::MutedUnitState(const Timer& timer)
	: OuterUnitState(timer)
{

}

bool MutedUnitState::canCast()const
{
	return false;
}

int MutedUnitState::getValue()const
{
	return MUTED_UNIT_STATE;
}

void MutedUnitState::showShortInfo()const
{
	std::cout << "<Muted: " << m_timer.getStartTime()
		+ m_timer.getDuration() - Arena::getCurrentRound() << "> ";
}

StatePtr MutedUnitState::clone()const
{
	return StatePtr(new MutedUnitState(m_timer));
}