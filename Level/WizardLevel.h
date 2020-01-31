#ifndef WIZARD_LEVEL_H_
#define WIZARD_LEVEL_H_

#include "Level.h"

class WizardLevel : public Level
{
public:
	WizardLevel(Unit* unit);
	WizardLevel& operator++()override;
private:
	enum
	{
		HP_PER_LVL = 5,
		MP_PER_LVL = 15,
		HP_REGEN_PER_LVL = 1,
		MP_REGEN_PER_LVL = 3,
		DMG_PER_LVL = 1,
		ARM_PER_LVL = 1,
		HP_RESTORE_PERCENT = 10,
		MP_RESTORE_PERSENT = 15
	};
};

#endif
