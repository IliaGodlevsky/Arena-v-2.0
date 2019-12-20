#include "../../Weapon/Weapon.h"

#include "WeaponFactory.h"

WeaponFactory::WeaponFactory()
{
	m_items.push_back(WeaponPtr(new Weapon("Club",
		CLUB_DAMAGE, CLUB_CRITICAL_PROPABILY)));
	m_items.push_back(WeaponPtr(new Weapon("Axe",
		AXE_DAMAGE, AXE_CRITICAL_PROPABILITY)));
	m_items.push_back(WeaponPtr(new Weapon("Sword",
		SWORD_DAMAGE, SWORD_CRITICAL_PROPABILITY)));
	m_items.push_back(WeaponPtr(new Weapon("Spear",
		SPEAR_DAMAGE, SPEAR_CRITICAL_PROPABILITY)));
}