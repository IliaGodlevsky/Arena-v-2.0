#pragma once

#include "Unit.h"

class Passive
{
public:
	Passive(std::string name, int propability = 20);
	virtual bool IsTriggered()const final;
	virtual int Effect(int damage)const = 0;
	virtual void Effect(spell_ptr<Magic>& spell)const = 0;
	virtual ~Passive() = 0;
protected:
	std::string name;
	int propability;
};

class Evasion : public Passive
{

};

class Critical : public Passive
{

};

class AbsorbDamage : public Passive
{

};