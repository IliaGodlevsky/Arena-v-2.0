#include "Arena/Arena.h"

extern ArenaActions<PREPARE_STEPS> prepares;

int main()
{
	set_terminate(myTerminate);
	auto& arena = Arena::getInstance();
	bool answer = YES;
	while (YES is answer) {
		try {
			arena.showMiniature();
			std::for_each(prepares.begin(), 
				prepares.end(), invoke);
			while (!arena.isGameOver())
				playSteps(arena);
			arena.showUnits();
			std::cout << "Became the winner\n";
			system("pause");
		}
		catch (std::exception& ex) { 
			exceptionMessage(ex); 
		}
		answer = static_cast<bool>(
			inputNumber(playAgainMsg, YES, NO));
		system("cls");
	}
}