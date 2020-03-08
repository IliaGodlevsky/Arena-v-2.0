#include "../Unit/Unit.h"

#include "WarriorLevel.h"

WarriorLevel::WarriorLevel() : Level()
{

}

WarriorLevel::WarriorLevel(Unit* unit)
	: Level(unit)
{

}

LevelPtr WarriorLevel::clone()const
{
	LevelPtr level = LevelPtr(new WarriorLevel());
	level->setLevel(m_level);
	return level;
}

WarriorLevel& WarriorLevel::operator++()
{
	return static_cast<WarriorLevel&>(Level::operator++());
}

int WarriorLevel::getAddedHpPerLevel()const
{
	return 15;
}

int WarriorLevel::getAddedMpPerLevel()const
{
	return 5;
}

int WarriorLevel::getAddedHpRegenPerLevel()const
{
	return 2;
}

int WarriorLevel::getAddedMpRegenPerLevel()const
{
	return 1;
}

int WarriorLevel::getAddedDamagePerLevel()const
{
	return 2;
}

int WarriorLevel::getAddedArmorPerLevel()const
{
	return 1;
}

int WarriorLevel::getHpRestorePercent()const
{
	return 14;
}

int WarriorLevel::getMpRestorePercent()const
{
	return 10;
}