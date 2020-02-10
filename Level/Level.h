#ifndef LEVEL_H_
#define LEVEL_H_

#include "../Globals/Globals.h"

class Level;
using LevelPtr = std::unique_ptr<Level>;

class Level
{
public:
	Level() = default;
	Level(Unit* unit);
	Level(const Level&) = default;
	virtual Level& operator++();
	virtual void setOwner(Unit* unit)final;
	virtual void setLevel(int level = 1)final;
	virtual ~Level() = default;
	operator int()const;
	virtual LevelPtr clone()const = 0;
protected:
	int m_level = 1;
private:
	virtual int getAddedHpPerLevel()const = 0;
	virtual int getAddedMpPerLevel()const = 0;
	virtual int getAddedHpRegenPerLevel()const = 0;
	virtual int getAddedMpRegenPerLevel()const = 0;
	virtual int getAddedDamagePerLevel()const = 0;
	virtual int getAddedArmorPerLevel()const = 0;
	virtual int getHpRestorePercent()const = 0;
	virtual int getMpRestorePercent()const = 0;
	virtual int getMaxLevel()const;
	Unit* m_unit = nullptr; // unit, that have this level class
};

#endif