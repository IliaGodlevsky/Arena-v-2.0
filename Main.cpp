#include "Arena/Arena.h"

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
			announceWinner(arena);
		}
		catch (std::exception& ex) { 
			exceptionMessage(ex); 
		}
		answer = static_cast<bool>(
			inputNumber(playAgainMsg, YES, NO));
		system("cls");
	}
}