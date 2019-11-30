#include "Arena.h"
#include "Armor.h"
#include "Battles.h"
#include "Decision.h"
#include "Globals.h"
#include "Magic.h"
#include "Unit.h"
#include "Vitals.h"
#include "Weapon.h"
#include "WeaponMagic.h"

// TODO: create namespace
int main()
{
	Arena& arena = Arena::getInstance();
	while (!arena.gameOver())
	{
		arena.scan();
		arena.castStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.attackStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.nextPlayer();
	}
}