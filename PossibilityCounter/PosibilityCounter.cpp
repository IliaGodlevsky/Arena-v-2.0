#include "../Globals/Globals.h"

#include "PosibilityCounter.h"

PosibilityCounter::PosibilityCounter(int posibility)
	: m_posibility(posibility)
{

}

constexpr int PosibilityCounter::getMaxPropability()const
{
	return 100;
}

PosibilityCounter::operator bool()const
{
	return randomNumber(getMaxPropability() - 1) < m_posibility;
}