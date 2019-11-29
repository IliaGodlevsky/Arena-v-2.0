#include "Level.h"
#include "Unit.h"

Level::Level(Unit* unit)
	: unit(unit)
{

}

Level Level::operator++(int i)
{
	Level temp = *this;
	level++;
	unit->health = unit->health + Vitals(HP_PER_LVL, 
		HP_PER_LVL, HP_REGEN_PER_LVL);
	unit->mana = unit->mana + Vitals(MP_PER_LVL,
		MP_PER_LVL, MP_REGEN_PER_LVL);
	unit->damage.ChangeValue(DMG_PER_LVL);
	unit->armor.ChangeValue(ARM_PER_LVL);
	return temp;
}

Level::operator int()const
{
	return level;
}