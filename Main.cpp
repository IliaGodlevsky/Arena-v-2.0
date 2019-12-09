#include "Arena.h"
#include "Armor.h"
#include "Battles.h"
#include "Decision.h"
#include "Magic.h"
#include "Unit.h"
#include "Vitals.h"
#include "Weapon.h"
#include "WeaponMagic.h"
#include "MagicFactory.h"
#include "WeaponFactory.h"
#include "ArmorFactory.h"
#include "ShieldFactory.h"
#include "ItemFactory.h"
#include "BadWeaponMagicException.h"

// TODO: create namespace
int main()
{
	Arena& arena = Arena::getInstance();

	arena.prepareUnits();

	ItemFactory<Magic> magicFactory
	(
		{ 
		new DamageBuffFactory(),
		new ArmorBuffFactory(),
		new ArmorAndDamageBuffFactory(),
		new OffsetDamageBuffFactory() 
		}
	);
	ItemFactory<Weapon> weaponFactory
	(
		{ 
			new AxeFactory(),
			new SwordFactory()
		}
	);
	ItemFactory<Armor> armorFactory
	(
		{
			new ArmorFactory(),
			new MailFactory(),
			new WizardCloakFactory(),
			new LegionerChainsFactory()
		}
	);
	ItemFactory<Shield> shieldFactory({ new ShieldFactory() });

	arena.giveArmorToUnits(armorFactory);
	arena.giveMagicToUnits(magicFactory);
	arena.giveShieldToUnits(shieldFactory);
	arena.giveWeaponToUnits(weaponFactory);

	while (!arena.gameOver())
	{
		arena.newRound();
		arena.showUnits();
		arena.castStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.showUnits();
		arena.attackStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.nextPlayer();
	}

	system("pause");
}