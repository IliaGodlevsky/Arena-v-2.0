#include "../Unit/Unit.h"

#include "WarriorLevel.h"

WarriorLevel::WarriorLevel(Unit* unit)
	: Level(unit)
{

}

WarriorLevel& WarriorLevel::operator++()
{
	m_unit->m_health = m_unit->m_health +
		Vitals(HP_PER_LVL, HP_PER_LVL, HP_REGEN_PER_LVL);
	m_unit->m_health.restore(HP_RESTORE_PERCENT);
	m_unit->m_mana.restore(MP_RESTORE_PERSENT);
	m_unit->m_mana = m_unit->m_mana +
		Vitals(MP_PER_LVL, MP_PER_LVL, MP_REGEN_PER_LVL);
	m_unit->m_damage.changeValue(DMG_PER_LVL);
	m_unit->m_armor.changeValue(ARM_PER_LVL);
	m_level++;
	return *this;
}