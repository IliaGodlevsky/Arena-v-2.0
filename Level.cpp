#include "Level.h"
#include "Unit.h"

Level::Level(Unit* unit)
	: m_unit(unit)
{

}

Level Level::operator++(int i)
{
	Level temp = *this;
	m_level++;
	m_unit->m_health = m_unit->m_health + Vitals(HP_PER_LVL, 
		HP_PER_LVL, HP_REGEN_PER_LVL);
	m_unit->m_mana = m_unit->m_mana + Vitals(MP_PER_LVL,
		MP_PER_LVL, MP_REGEN_PER_LVL);
	m_unit->m_damage.changeValue(DMG_PER_LVL);
	m_unit->m_armor.changeValue(ARM_PER_LVL);
	return temp;
}

Level::operator int()const
{
	return m_level;
}