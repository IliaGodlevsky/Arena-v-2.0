#include "Arena/Arena.h"

int main()
{
	set_terminate(myTerminate);
	auto& arena = Arena::getInstance();
	bool answer = YES;
	while (YES == answer)
	{
		try 
		{
			arena.prepareUnits();
			arena.proposeToPlayTeams();
			arena.setStartUnit();
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
			arena.showUnits();
			std::cout << "Became the winner\n";
			system("pause");
		}
		catch (std::exception& ex) { exceptionMessage(ex); }
		answer = static_cast<bool>(inputNumber("Play again:"
			" 1 - yes, 0 - no: ", YES, NO));
		system("cls");
	}
}