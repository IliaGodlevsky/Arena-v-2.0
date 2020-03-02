#include "Arena/ArenaDelegate.h"

int main(){
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
		catch (ArenaException& ex) {
			exceptionMessage(ex);
			exit(EXIT_FAILURE);
		}
		catch (std::exception& ex) {
			exceptionMessage(ex);
		}
	} while (wantsToPlayAgain());
}