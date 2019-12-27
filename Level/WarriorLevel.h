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
		HP_PER_LVL = 20,
		MP_PER_LVL = 5,
		HP_REGEN_PER_LVL = 3,
		MP_REGEN_PER_LVL = 1,
		DMG_PER_LVL = 1,
		ARM_PER_LVL = 1,
		HP_RESTORE_PERCENT = 30,
		MP_RESTORE_PERSENT = 13
	};
};

#endif