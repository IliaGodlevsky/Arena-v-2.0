#include "MutedUnitState.h"

#include "../../Magic/Magic.h"
#include "../../Decision/Decision.h"
#include "../../Unit/Unit.h"

MutedUnitState::MutedUnitState(Time time)
	: OuterUnitState(time)
{

}

bool MutedUnitState::canCast()const
{
	return false;
}

int MutedUnitState::getValue()const
{
	return 1;
}

void MutedUnitState::showShortInfo()const
{
	std::cout << "<Muted: " << getDurationRemained() << "> ";
}

StatePtr MutedUnitState::clone()const
{
	return StatePtr(new MutedUnitState(m_time));
}