#include <random>

#include "PosibilityCounter.h"

PosibilityCounter::PosibilityCounter(int posibility)
	: posibility(posibility)
{

}

bool PosibilityCounter::IsChance()const
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> distribution(MAX_PROPABILITY);
	return distribution(generator) <= posibility;
}