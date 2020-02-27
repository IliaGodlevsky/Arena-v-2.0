#include "Arena/Arena.h"

int main(){
	set_terminate(myTerminate);
	auto& arena = Arena::getInstance();
	do {
		try {
			arena.showMiniature();
			for (auto step : prepareSteps)
				invoke(step);
			while (!arena.isGameOver())
				playGameSteps(arena);
			announceWinner(arena);
		}
		catch (std::exception& ex) { 
			exceptionMessage(ex);
		}
		system("cls");
	} while (inputNumber(playAgainMsg, YES, NO));
}