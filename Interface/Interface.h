#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "../Globals/Globals.h"

/*interface for magic, that after expiry 
must take off its effect from unit*/
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

/* interface for magic, that costs mana*/
struct IManaCost
{
public:
	IManaCost(int manaCost);
	int getCost()const;
	virtual ~IManaCost() = default;
protected:
	int m_manaCost = 0;
};

// interface for magic, that must expire after some period
struct IExpirable
{
	virtual bool isExpired()const = 0;
	virtual ~IExpirable() = default;
};

#endif
