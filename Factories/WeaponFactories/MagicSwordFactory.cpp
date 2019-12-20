#include "../../Weapon/MagicSword.h"
#include "../../Magic/WeaponMagic/DegenerateMagic.h"

#include "MagicSwordFactory.h"


MagicSwordFactory::MagicSwordFactory()
{
	m_items.push_back(WeaponPtr(new MagicSword("Hell sword", HELL_SWORD_DAMAGE,
		MagicPtr(new DegenerateMagic("Soul burn",
			SOUL_BURN_DURATION, SOUL_BURN_DEGENERATE, SOUL_BURN_PROPABILITY)))));
	m_items.push_back(WeaponPtr(new MagicSword("Gladiators sword", GLADIATOR_SWORD_DAMAGE,
		MagicPtr(new DegenerateMagic("Open wounds",
			OPEN_WOUNDS_DURATION, OPEN_WOUNDS_DEGENERATE, OPEN_WOUNDS_PROPABILITY)))));
}