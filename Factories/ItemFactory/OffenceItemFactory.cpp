#include "OffenceItemFactory.h"

#include "../MagicFactories/BuffFactories/OffsetDamageBuffFactory.h"
#include "../MagicFactories/BuffFactories/DamageBuffFactory.h"
#include "../MagicFactories/AttackFactories/PoisonMagicFactory.h"
#include "../ArmorFactories/MailFactory.h"
#include "../ArmorFactories/ArmorFactory.h"
#include "../WeaponFactories/MagicAxeFactory.h"
#include "../WeaponFactories/WeaponFactory.h"
#include "../ShieldFactories/ShieldFactory.h"

OffenceItemFactory::OffenceItemFactory()
{
	m_magicFactories.push_back(new OffsetDamageBuffFactory());
	m_magicFactories.push_back(new DamageBuffFactory());
	m_magicFactories.push_back(new PoisonMagicFactory());
	m_armorFactories.push_back(new MailFactory());
	m_armorFactories.push_back(new ArmorFactory());
	m_shieldFactories.push_back(new ShieldFactory());
	m_weaponFactories.push_back(new MagicAxeFactory());
	m_weaponFactories.push_back(new WeaponFactory());
}