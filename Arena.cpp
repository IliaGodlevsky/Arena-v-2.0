#include "Arena.h"

int Arena::round = 0;

Arena::Arena()
{
	// enter code with choosing magic and units
}

int Arena::CurrentRound()
{
	return round;
}

Arena& Arena::GetInstance()
{
	static Arena instance;
	return instance;
}

void Arena::TakeOfLosers()
{
	for (size_t i = 0; i < arena.size(); i++)
	{
		if (arena[i]->health.IsDead())
		{
			arena.erase(arena.begin() + i);
			i--;
		}
	}
}

bool Arena::GameOver()const
{
	return arena.size() == 1;
}

void Arena::GameCycle()
{
	for (size_t i = 0; i < arena.size(); i++)
	{
		arena[i]->ShowUnitName();
	}
}