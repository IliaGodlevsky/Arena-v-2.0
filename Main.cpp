#include "Arena/Arena.h"

#include <csignal>

int main()
{
	set_terminate(myTerminate);
	auto& arena = Arena::getInstance();
	bool answer = YES;
	while (YES == answer)
	{
		try 
		{
			system("cls");
			arena.prepareUnits();
			arena.proposeToPlayTeams();
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
	}
}