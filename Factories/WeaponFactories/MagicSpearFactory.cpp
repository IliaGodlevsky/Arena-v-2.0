#include "../../Magic/WeaponMagic/CorruptionMagic.h"
#include "../../Weapon/MagicSpear.h"

#include "MagicSpearFactory.h"

MagicSpearFactory::MagicSpearFactory()
{
	m_items.push_back(WeaponPtr(new MagicSpear("Amazonian spear", AMAZONE_SPEAR_DAMAGE,
		MagicPtr(new CorruptionMagic("Hole", Timer(HOLE_DURATION), HOLE_ARMOR_REDUCE, HOLE_POSSIBILITY)))));
	m_items.push_back(WeaponPtr(new MagicSpear("Gladiator spear", GLADIATORS_SPEAR_DAMAGE, 
		MagicPtr(new CorruptionMagic("Pierce", Timer(PIERCE_DURATION), PIERCE_ARMOR_REDUCE, PIERCE_POSSIBILTY)))));
}