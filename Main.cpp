#include "Arena/Arena.h"
#include "Unit/Unit.h"

int main()
{
	Arena& arena = Arena::getInstance();

	arena.prepareUnits();

	while (!arena.isGameOver())
	{
		arena.showUnits();
		arena.playCastStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.showUnits();
		arena.playAttackStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.goNextUnit();
	}

	system("pause");
}