#include "Arena.h"
#include "Armor.h"
#include "Battles.h"
#include "Decision.h"
#include "Magic.h"
#include "Unit.h"
#include "Vitals.h"
#include "Weapon.h"
#include "WeaponMagic.h"
#include "BuffFactories.h"
#include "DebuffMagicFactory.h"
#include "AttackMagicFactory.h"
#include "NeutralMagicFactory.h"
#include "WeaponFactory.h"
#include "ArmorFactory.h"
#include "ShieldFactory.h"
#include "ItemFactory.h"
#include "BadWeaponMagicException.h"

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
		new OffsetDamageBuffFactory(),
		new ArmorBuffFactory(),
		new DamageBuffFactory(),
		new ArmorAndDamageBuffFactory(),
		new SilenceFactory(),
		new AttackMagicFactory(),
		new AttackAndStunMagicFactory(),
		new PoisonMagicFactory(),
		new PoisonAndAttackMagicFactory(),
		new NeutralMagicFactory()
		}
	);
	arena.giveMagicToUnits(magicFactory);

	try
	{
		ItemFactory<Weapon> weaponFactory
		(
			{
				new MagicAxeFactory(),
				new MagicSwordFactory(),
				new MagicSpearFactory(),
				new MagicClubFactory(),
				new WeaponFactory()
			}
		);
		arena.giveWeaponToUnits(weaponFactory);
	}
	catch (BadWeaponMagicException&ex)
	{
		std::cout << ex.what() << std::endl;
		return 1;
	}

	ItemFactory<Armor> armorFactory
	(
		{
			new ArmorFactory(),
			new MailFactory(),
			new WizardCloakFactory(),
			new LegionerChainsFactory()
		}
	);
	arena.giveArmorToUnits(armorFactory);

	ItemFactory<Shield> shieldFactory
	(
		{ 
			new ShieldFactory() 
		}
	);
	arena.giveShieldToUnits(shieldFactory);
	
	while (!arena.isGameOver())
	{
		arena.showUnits();
		arena.playCastStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.showUnits();
		arena.playAttackStep();
		arena.rewardKiller();
		arena.takeOfLosers();
		arena.goNextUnit();
	}

	system("pause");
}