#include "Arena/Arena.h"

int main()
{
	auto& arena = Arena::getInstance();
	bool answer = YES;
	while (YES == answer)
	{
		try {

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
		catch (BadWeaponMagicException& ex) { exceptionMessage(ex); }
		catch (BadEquipmentException& ex) { exceptionMessage(ex); }
		catch (EmptyContainerException& ex) { exceptionMessage(ex); }
		catch (BadIncomingMagicException& ex) { exceptionMessage(ex); }
		catch (ArenaException& ex) { exceptionMessage(ex); }
		catch (std::exception& ex) { exceptionMessage(ex); }
		answer = static_cast<bool>(inputNumber("Play again:"
			" 1 - yes, 0 - no: ", YES, NO));
		system("cls");
	}
	system("pause");
}