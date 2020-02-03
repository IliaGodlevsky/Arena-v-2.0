#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "../Globals/Globals.h"

struct IUneffect
{
	virtual void uneffectUnit(Unit& unit) = 0;
	virtual ~IUneffect() = default;
};

struct IBuff
{
	virtual bool isBuff()const = 0;
	virtual ~IBuff() = default;
};

struct IDispelable
{
	virtual bool isDispelable()const = 0;
	virtual ~IDispelable() = default;
};

struct IManaCost
{
	virtual int getCost()const = 0;
	virtual ~IManaCost() = default;
};

struct IDuration
{
	virtual void setStartTime(int round) = 0;
	virtual bool isExpired()const = 0;
	virtual int getDuration()const = 0;
	virtual int getStartTime()const = 0;
	int getDurationRemained()const;
	virtual ~IDuration() = default;
};

#endif
