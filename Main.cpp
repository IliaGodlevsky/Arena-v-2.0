#include "Arena/Arena.h"

int main(){
	set_terminate(myTerminate);
	auto& arena = Arena::getInstance();
	bool wantsToPlay;
	do {
		try {
			arena.showMiniature();
			std::for_each(prepareSteps.begin(), 
				prepareSteps.end(), invoke);
			while (!arena.isGameOver())
				playGameSteps(arena);
			announceWinner(arena);
		}
		catch (std::exception& ex) { 
			exceptionMessage(ex);
		}
		wantsToPlay = static_cast<bool>(
			inputNumber(playAgainMsg, YES, NO));
		system("cls");
	} while (wantsToPlay);
}