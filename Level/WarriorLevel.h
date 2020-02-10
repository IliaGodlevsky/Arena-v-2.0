#ifndef WARRIOR_LEVEL_H_
#define WARRIOR_LEVEL_H_

#include "Level.h"

class WarriorLevel : public Level
{
public:
	WarriorLevel() = default;
	WarriorLevel(Unit* unit);
	LevelPtr clone()const override;
	WarriorLevel& operator++()override;
private:
	int getAddedHpPerLevel()const override;
	int getAddedMpPerLevel()const override;
	int getAddedHpRegenPerLevel()const override;
	int getAddedMpRegenPerLevel()const override;
	int getAddedDamagePerLevel()const override;
	int getAddedArmorPerLevel()const override;
	int getHpRestorePercent()const override;
	int getMpRestorePercent()const override;
};

#endif