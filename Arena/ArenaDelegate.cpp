#include "ArenaDelegate.h"

void playGameStep(Arena& arena, const GameStep& method)
{
	arena.showUnits();
	invoke(method);
	arena.takeOfLosers();
}

void playGameSteps(Arena& arena)
{
	enum { CAST_STEP, ATTACK_STEP };
	static unsigned gameStep = CAST_STEP;
	playGameStep(arena, gameSteps.at(gameStep));
	if (++gameStep >= gameSteps.size())
	{
		gameStep = CAST_STEP;
		arena.goNextUnit();
	}
}

void announceWinner(Arena& arena)
{
	arena.showUnits();
	std::cout << "Became the winner\n";
}