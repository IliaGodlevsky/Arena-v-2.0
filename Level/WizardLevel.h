#ifndef WIZARD_LEVEL_H_
#define WIZARD_LEVEL_H_

#include "Level.h"

class WizardLevel : public Level
{
public:
	WizardLevel();
	WizardLevel(Unit* unit);
	LevelPtr clone()const override;
	WizardLevel& operator++()override;
private:
	int getAddedHpPerLevel()const override;
	int getAddedMpPerLevel()const override;
	int getAddedHpRegenPerLevel()const override;
	int getAddedMpRegenPerLevel()const override;
	int getAddedDamagePerLevel()const override;
	int getAddedArmorPerLevel()const override;
	int getHpRestorePercent()const override;
	int getMpRestorePercent()const override;
};

#endif
