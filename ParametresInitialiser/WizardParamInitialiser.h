#ifndef WIZARD_PARAM_INIT_H_
#define WIZARD_PARAM_INIT_H_

#include "ParametresInitialiser.h"

class WizardParamInitialiser : public ParametresInitialiser
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
