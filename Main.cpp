#include "Arena/Arena.h"

int main()
{
	set_terminate(myTerminate);
	auto& arena = Arena::getInstance();
	bool wantsToPlay = YES;
	while (wantsToPlay) {
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
		wantsToPlay = static_cast<bool>(
			inputNumber(playAgainMsg, YES, NO));
		system("cls");
	}
}