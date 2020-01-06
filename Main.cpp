#include "Arena/Arena.h"

int main()
{
	auto& arena = Arena::getInstance();
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
	}
	catch (BadWeaponMagicException& ex) { exceptionMessage(ex); }
	catch (BadEquipmentException& ex) { exceptionMessage(ex); }
	catch (EmptyContainerException&ex) { exceptionMessage(ex); }
	catch (ArenaException& ex) { exceptionMessage(ex); }
	catch (std::exception& ex) { exceptionMessage(ex); }

	system("pause");
}