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

int main()
{
	Arena& arena = Arena::GetInstance();
	while (!arena.GameOver())
		arena.GameCycle();
}