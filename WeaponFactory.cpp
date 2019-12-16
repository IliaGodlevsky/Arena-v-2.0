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

int WeaponFactory::getChanceOfCreation()const
{
	return 72;
}

MagicSwordFactory::MagicSwordFactory()
{
	m_items.push_back(WeaponPtr(new MagicSword("Hell sword",HELL_SWORD_DAMAGE,
		MagicPtr(new Degenerate("Soul burn", 
			SOUL_BURN_DURATION, SOUL_BURN_DEGENERATE, SOUL_BURN_PROPABILITY)))));
	m_items.push_back(WeaponPtr(new MagicSword("Gladiators sword", GLADIATOR_SWORD_DAMAGE, 
		MagicPtr(new Degenerate("Open wounds", 
			OPEN_WOUNDS_DURATION, OPEN_WOUNDS_DEGENERATE, OPEN_WOUNDS_PROPABILITY)))));
}

int MagicSwordFactory::getChanceOfCreation()const
{
	return 10;
}

MagicAxeFactory::MagicAxeFactory()
{
	m_items.push_back(WeaponPtr(new MagicAxe("Butcher axe", BUTCHER_AXE_DAMAGE, 
		MagicPtr(new Crush("Head strike", HEAD_STRIKE_DAMAGE, HEAD_STRIKE_PROPABILITY)))));

}

int MagicAxeFactory::getChanceOfCreation()const
{
	return 10;
}