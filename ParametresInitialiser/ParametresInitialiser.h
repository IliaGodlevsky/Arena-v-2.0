#ifndef PARAM_INIT_H_
#define PARAM_INIT_H_

#include "../Globals/Globals.h"

class ParametresInitialiser;
using ParamInitPtr = std::unique_ptr<ParametresInitialiser>;

class ParametresInitialiser
{
public:
	virtual int getStartHp()const = 0;
	virtual int getStartMp()const = 0;
	virtual int getStartHpRegen()const = 0;
	virtual int getStartMpRegen()const = 0;
	virtual int getStartDamage()const = 0;
	virtual int getStartArmor()const = 0;
	virtual ~ParametresInitialiser() = default;
};

#endif