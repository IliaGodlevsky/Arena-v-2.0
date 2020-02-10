#ifndef WARRIOR_PARAM_INIT_H_
#define WARRIOR_PARAM_INIT_H_

#include "ParametresInitialiser.h"

class WarriorParamInitialiser : public ParametresInitialiser
{
public:
	int getStartHp()const;
	int getStartMp()const;
	int getStartHpRegen()const;
	int getStartMpRegen()const;
	int getStartDamage()const;
	int getStartArmor()const;
};
#endif
