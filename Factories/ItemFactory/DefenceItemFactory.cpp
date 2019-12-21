#include "DefenceItemFactory.h"

#include "../ShieldFactories/ShieldFactory.h"
#include "../MagicFactories/DebuffFactories/DamageDebuffFactory.h"
#include "../MagicFactories/DebuffFactories/SilenceFactory.h"
#include "../MagicFactories/AttackFactories/AttackAndStunMagicFactory.h"
#include "../WeaponFactories/MagicSwordFactory.h"
#include "../ArmorFactories/LegionerChainsFactory.h"
#include "../ArmorFactories/ArmorFactory.h"
#include "../MagicFactories/AttackFactories/AttackMagicFactory.h"
#include "../WeaponFactories/MagicSwordFactory.h"
#include "../WeaponFactories/WeaponFactory.h"

DefenceItemFactory::DefenceItemFactory()
{
	m_magicFactories.push_back(new DamageDebuffFactory());
	m_magicFactories.push_back(new SilenceFactory());
	m_magicFactories.push_back(new AttackAndStunMagicFactory());
	m_magicFactories.push_back(new AttackMagicFactory());
	m_shieldFactories.push_back(new ShieldFactory());
	m_armorFactories.push_back(new LegionerChainsFactory());
	m_armorFactories.push_back(new ArmorFactory());
	m_weaponFactories.push_back(new MagicSwordFactory());
	m_weaponFactories.push_back(new WeaponFactory());
}