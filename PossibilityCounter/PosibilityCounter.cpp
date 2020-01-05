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

int PosibilityCounter::getPosibility()const
{
	return m_posibility;
}

bool PosibilityCounter::operator==(const PosibilityCounter& counter)const
{
	return m_posibility == counter.m_posibility;
}