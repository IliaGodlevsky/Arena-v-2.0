#include "Arena/Arena.h"

int main(){
	auto& arena = Arena::getInstance();
	do {
		try {
			arena.showMiniature();
			arena.setNumberOfUnits();
			arena.prepareUnits();
			arena.proposeToPlayTeams();
			arena.setStartUnit();
			arena.playArena();
			arena.announceWinner();
		}
		catch (std::exception& ex) {
			exceptionMessage(ex);
		}
	} while (wantsToPlayAgain());
}