#include "../Unit/Unit.h"

#include "WizardLevel.h"

WizardLevel::WizardLevel() : Level()
{

}

WizardLevel::WizardLevel(Unit* unit)
	: Level(unit)
{

}

WizardLevel& WizardLevel::operator++()
{
	return static_cast<WizardLevel&>(Level::operator++());
}

LevelPtr WizardLevel::clone()const
{
	LevelPtr level = LevelPtr(new WizardLevel());
	level->setLevel(m_level);
	return level;
}

int WizardLevel::getAddedHpPerLevel()const
{
	return 5;
}

int WizardLevel::getAddedMpPerLevel()const
{
	return 15;
}

int WizardLevel::getAddedHpRegenPerLevel()const
{
	return 1;
}

int WizardLevel::getAddedMpRegenPerLevel()const
{
	return 3;
}

int WizardLevel::getAddedDamagePerLevel()const
{
	return 1;
}

int WizardLevel::getAddedArmorPerLevel()const
{
	return 1;
}

int WizardLevel::getHpRestorePercent()const
{
	return 10;
}

int WizardLevel::getMpRestorePercent()const
{
	return 15;
}