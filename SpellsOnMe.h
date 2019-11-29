#pragma once

#ifndef SPELLS_ON_ME
#define SPELLS_ON_ME

#include "Globals.h"

class SpellsOnMe : public Spells
{
public:
	SpellsOnMe(Unit* unit);
	void TakeOfExpired(int round);
	size_t HaveSpell(const MagicPtr& spell)const;
	void Expire(size_t spell_index);
	void ExpireAllSpells();
	void TakeSpell(MagicPtr&& magic);
	void ShowFullInfo()const;
	void ShowShortInfo()const;
private:
	Unit* unit;
};
#endif