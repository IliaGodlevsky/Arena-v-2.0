#include "../../Weapon/MagicAxe.h"
#include "../../Magic/WeaponMagic/CrushMagic.h"

#include "MagicAxeFactory.h"

MagicAxeFactory::MagicAxeFactory()
{
	m_items.push_back(WeaponPtr(new MagicAxe("Butcher axe", BUTCHER_AXE_DAMAGE,
		MagicPtr(new CrushMagic("Head strike", HEAD_STRIKE_DAMAGE, HEAD_STRIKE_PROPABILITY)))));
	m_items.push_back(WeaponPtr(new MagicAxe("Chopper axe",CHOPPER_AXE_DAMAGE,
		MagicPtr(new CrushMagic("Knock", KNOCK_DAMAGE, KNOCK_PROPABILITY)))));

}