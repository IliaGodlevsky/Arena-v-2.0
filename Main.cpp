#include "Arena/Arena.h"
#include "Unit/Unit.h"
#include "Unit/Wizard.h"
#include "Factories/UnitFactory/WizardFactory.h"
#include "Magic/AttackMagic/AttackAndStunMagic.h"
#include "Magic/DebuffMagic/ArmorDebuffMagic.h"

int main()
{
	//WizardFactory wf;
	//UnitPtr unit = wf.createUnit();
	//UnitPtr unit2 = unit->getPureClone();
	//unit->showFullInfo();
	//std::cout << std::endl;
	//unit2->showFullInfo();
	//system("pause");
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