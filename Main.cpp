#include "Arena/Arena.h"

int main()
{
	auto& arena = Arena::getInstance();

	arena.prepareUnits();

	while (!arena.isGameOver())
	{
		arena.showUnits();
		arena.playCastStep();
		arena.takeOfLosers();
		arena.showUnits();
		arena.playAttackStep();
		arena.takeOfLosers();
		arena.goNextUnit();
	}
    
	system("pause");
}