#ifndef WARRIOR_LEVEL_H_
#define WARRIOR_LEVEL_H_

#include "Level.h"

class WarriorLevel : public Level
{
public:
	WarriorLevel(Unit* unit);
	WarriorLevel& operator++()override;
private:
	enum
	{
		HP_PER_LVL = 15,
		MP_PER_LVL = 5,
		HP_REGEN_PER_LVL = 2,
		MP_REGEN_PER_LVL = 1,
		DMG_PER_LVL = 2,
		ARM_PER_LVL = 1,
		HP_RESTORE_PERCENT = 14,
		MP_RESTORE_PERSENT = 10
	};
};

#endif