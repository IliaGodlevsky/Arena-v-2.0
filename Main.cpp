#include "Arena/Arena.h"
#include "Unit/Unit.h"
#include "Factories/Factory.h"

int main()
{
	Arena& arena = Arena::getInstance();

	arena.prepareUnits();

	while (!arena.isGameOver())
	{
		system("cls");
		std::cout << "Round: " << arena.getCurrentRound() << std::endl;
		arena.showUnits();
		arena.playCastStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		system("cls");
		arena.showUnits();
		arena.playAttackStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.goNextUnit();
	}

	system("pause");
}