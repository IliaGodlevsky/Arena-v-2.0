#pragma once

#ifndef LEVEL_H_
#define LEVEL_H_

#include "Globals.h"

class Level
{
public:
	Level(Unit& unit);
	Level operator++(int i);
	void ShowFullInfo()const;
	void ShowShortInfo()const;
private:
	enum { MAX_LVL = 5 };
	enum
	{
		HP_PER_LEVEL = 15,
		MP_PER_LVL = 10,
		HP_REGEN_PER_LVL = 2,
		MP_REGEN_PER_LVL = 2,
		DMG_PER_LVL = 2, 
		ARM_PER_LVL = 1 
	};
	int level = 1;
	Unit* unit;
};

#endif