#include "MagicStaffFactory.h"

#include "../../Magic/WeaponMagic/DegenerateMagic.h"
#include "../../Weapon/MagicStaff.h"

MagicStaffFactory::MagicStaffFactory()
{
	m_items.push_back(WeaponPtr(new MagicStaff("Wizard staff", WIZARD_STAFF_DAMAGE, 
		MagicPtr(new DegenerateMagic("Inner fire", Timer(INNER_FIRE_DURATION), 
			INNER_FIRE_DAMAGE_PER_ROUND, INNER_FIRE_POSSIBILITY)))));
	m_items.push_back(WeaponPtr(new MagicStaff("Archmage staff", ARCHMAGE_STAFF_DAMAGE,
		MagicPtr(new DegenerateMagic("Inner fire", Timer(LIFE_TRAP_DURATION),
			LIFE_TRAP_DAMAGE_PER_ROUND, LIFE_TRAP_POSSIBILITY)))));
	m_items.push_back(WeaponPtr(new MagicStaff("Ancient staff", ANCIENT_STAFF_DAMAGE,
		MagicPtr(new DegenerateMagic("Ancient course", Timer(ANCIENT_DAMAGE_DURATION),
			ANCIENT_COURSE_DAMAGE_ROUND, ANCIENT_COURSE_POSIBILITY)))));
}