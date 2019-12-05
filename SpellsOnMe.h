#pragma once

#ifndef SPELLS_ON_ME
#define SPELLS_ON_ME

#include "Globals.h"

class SpellsOnMe : public Spells
{
public:
	SpellsOnMe(Unit* unit);
	void takeOfExpiredMagic(int round);
	size_t getMagicIndex(const MagicPtr& magic)const;
	void expireMagic(size_t magicIndex);
	void expireAllSpells();
	void takeMagic(const MagicPtr& magic);
	void showFullInfo()const;
	void showShortInfo()const;
private:
	Unit* m_unit; // unit, that have this vector of spells
};
#endif // SPELLS_ON_ME