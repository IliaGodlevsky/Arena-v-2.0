#include "Arena/Arena.h"
#include "Unit/Unit.h"
#include "Factories/Factory.h"

void round();

int main()
{
	Arena& arena = Arena::getInstance();

	arena.prepareUnits();

	while (!arena.isGameOver())
	{
		system("cls");
		round();
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

void round()
{
	std::cout << "Round: "
		<< Arena::getCurrentRound() + 1 << std::endl;
}