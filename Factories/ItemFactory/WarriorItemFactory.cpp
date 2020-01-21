#include "WarriorItemFactory.h"

#include "../ArmorFactories/MailFactory.h"
#include "../ArmorFactories/ArmorFactory.h"
#include "../WeaponFactories/MagicSwordFactory.h"
#include "../WeaponFactories/MagicSpearFactory.h"
#include "../WeaponFactories/MagicClubFactory.h"
#include "../MagicFactories/BuffFactories/DamageBuffFactory.h"
#include "../MagicFactories/BuffFactories/ArmorAndDamageBuffFactory.h"
#include "../MagicFactories/BuffFactories/OffsetDamageBuffFactory.h"
#include "../MagicFactories/BuffFactories/ArmorBuffFactory.h"
#include "../MagicFactories/AttackFactories/PoisonMagicFactory.h"
#include "../MagicFactories/AttackFactories/PoisonAndAttackMagicFactory.h"
#include "../ShieldFactories/MagicShieldFactory.h"
#include "../ShieldFactories/ShieldFactory.h"

WarriorItemFactory::WarriorItemFactory()
{
	m_armorFactories.push_back(new MailFactory());
	m_armorFactories.push_back(new ArmorFactory());
	m_weaponFactories.push_back(new MagicSwordFactory());
	m_weaponFactories.push_back(new MagicSpearFactory());
	m_weaponFactories.push_back(new MagicClubFactory());
	m_magicFactories.push_back(new OffsetDamageBuffFactory());
	m_magicFactories.push_back(new ArmorAndDamageBuffFactory());
	m_magicFactories.push_back(new ArmorBuffFactory());
	m_magicFactories.push_back(new DamageBuffFactory());
	m_magicFactories.push_back(new PoisonMagicFactory());
	m_magicFactories.push_back(new PoisonAndAttackMagicFactory());
	m_shieldFactories.push_back(new ShieldFactory());
	m_shieldFactories.push_back(new MagicShieldFactory());
}