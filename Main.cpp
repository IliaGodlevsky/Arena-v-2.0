#include "Arena/Arena.h"
#include "Unit/Unit.h"
#include "Unit/Wizard.h"
#include "Factories/UnitFactory/WizardFactory.h"
#include "Magic/AttackMagic/AttackAndStunMagic.h"
#include "Magic/DebuffMagic/ArmorDebuffMagic.h"

int main()
{
	auto& arena = Arena::getInstance();

	arena.prepareUnits();

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
    
	system("pause");
}