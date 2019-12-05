#pragma once

#ifndef LEVEL_H_
#define LEVEL_H_

#include "Globals.h"

class Level
{
public:
	Level(Unit* unit);
	Level operator++(int i);
	operator int()const;
private:
	enum { MAX_LVL = 5 };
	enum
	{
		HP_PER_LVL = 15,
		MP_PER_LVL = 10,
		HP_REGEN_PER_LVL = 2,
		MP_REGEN_PER_LVL = 2,
		DMG_PER_LVL = 2, 
		ARM_PER_LVL = 1 
	};
	int m_level = 1;
	Unit* m_unit; // unit, that have this level class
};

#endif // LEVEL_H_