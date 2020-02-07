#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "../Globals/Globals.h"
#include "../Timer/Timer.h"

/*interface for magic, that after expiry 
must take off its effect from unit*/
interface IUneffect
{
	virtual void uneffectUnit(Unit& unit) = 0;
	virtual ~IUneffect() = default;
};

interface IBuff
{
	virtual bool isBuff()const = 0;
	virtual ~IBuff() = default;
};

interface IDispelable
{
	virtual bool isDispelable()const = 0;
	virtual ~IDispelable() = default;
};

/* interface for magic, that costs mana*/
interface IManaCost
{
public:
	IManaCost(int manaCost);
	int getCost()const;
	virtual ~IManaCost() = default;
protected:
	int m_manaCost = 0;
};

// interface for magic, that must expire after some period
interface IDuration
{
public:
	IDuration(Timer timer);
	virtual void setStartTime(int round) = 0;
	virtual bool isExpired()const = 0;
	virtual int getDuration()const = 0;
	virtual int getStartTime()const = 0;
	int getDurationRemained()const;
	void expire();
	virtual ~IDuration() = default;
protected:
	Timer m_timer;
};

#endif
