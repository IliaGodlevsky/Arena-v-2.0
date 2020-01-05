#ifndef LEVEL_H_
#define LEVEL_H_

#include "../Globals/Globals.h"

class Level
{
public:
	Level(Unit* unit);
	Level(const Level&) = default;
	virtual Level& operator++();
	virtual void setOwner(Unit* unit)final;
	virtual ~Level() = default;
	operator int()const;
protected:
	int m_level = 1;
	Unit* m_unit = nullptr; // unit, that have this level class
};

#endif