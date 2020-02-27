#include "Arena/Arena.h"

int main(){
	auto& arena = Arena::getInstance();
	bool wantsToPlayAgain;
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
		wantsToPlayAgain = static_cast<bool>(
			inputNumber(playAgainMsg, YES, NO));
		system("cls");
	} while (wantsToPlayAgain); 
}