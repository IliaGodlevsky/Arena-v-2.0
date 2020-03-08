#include "../Unit/Unit.h"

#include "Level.h"

Level::Level()
	: Level(nullptr)
{

}

Level::Level(Unit* unit)
	: m_unit(unit), m_level(getStartLevelValue())
{

}

void Level::setLevel(int level)
{
	m_level = level;
}

Level& Level::operator++()
{
	m_unit->m_health.restore(getHpRestorePercent());
	m_unit->m_mana.restore(getMpRestorePercent());
	if (m_level < getMaxLevel())
	{
		m_unit->m_health = m_unit->m_health +
			Vitals(getAddedHpPerLevel(), 
				getAddedHpPerLevel(), 
				getAddedHpRegenPerLevel());
		m_unit->m_mana = m_unit->m_mana +
			Vitals(getAddedMpPerLevel(), 
				getAddedMpPerLevel(), 
				getAddedMpRegenPerLevel());
		m_unit->m_damage.changeValue(getAddedDamagePerLevel());
		m_unit->m_armor.changeValue(getAddedArmorPerLevel());
		m_level++;
	}
	return *this;
}

Level::operator int()const
{
	return m_level;
}

void Level::setOwner(Unit* unit)
{
	m_unit = unit;
}

int Level::getMaxLevel()const
{
	return 6;
}

int Level::getStartLevelValue()const
{
	return 1;
}