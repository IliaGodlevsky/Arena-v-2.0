#include <random>

#include "PosibilityCounter.h"

PosibilityCounter::PosibilityCounter(int posibility)
	: m_posibility(posibility)
{

}

int PosibilityCounter::getMaxPropability()const
{
	return 100;
}

PosibilityCounter::operator bool()const
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> distribution(getMaxPropability());
	return distribution(generator) <= m_posibility;
}