#pragma once

#ifndef MAGIC_H_
#define MAGIC_H_

#include "Unit.h"

class Magic
{
public:
	virtual void Effect(Unit* unit) = 0;
private:
	int mana_cost;
	int duration;
};
#endif