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
#include "MagicFactory.h"
#include "WeaponFactory.h"
#include "ArmorFactory.h"

// TODO: create namespace
int main()
{
	AllItemFactory<Magic> magicFactory({ 
		new DamageBuffFactory(),
		new ArmorBuffFactory(),
		new OffsetDamageBuffFactory(),
		new ArmorAndDamageBuffFactory() });
	AllItemFactory<Weapon> weaponFactory({ 
		new SwordFactory(),
		new AxeFactory() });
	AllItemFactory<Armor> armorFactory({ 
		new ArmorFactory(),
		new MailFactory(),
		new WizardCloakFactory(),
		new LegionerChainsFactory() });

	Arena& arena = Arena::getInstance();

	arena.prepareUnits();
	arena.giveMagicToUnits(magicFactory);
	arena.giveWeaponToUnits(weaponFactory);
	arena.giveArmorToUnits(armorFactory);

	while (!arena.gameOver())
	{
		arena.newRound();
		arena.castStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.attackStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.nextPlayer();
	}
}