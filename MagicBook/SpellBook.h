#pragma once

#ifndef SPELLBOOK_H_
#define SPELLBOOK_H_

#include "Globals.h"

class SpellBook : public Spells
{
public:
	SpellBook(Unit* unit);
	bool canCastAnySpell()const;
	void showFullInfo()const;
	void showShortInfo()const;
	void magicList()const;
	void takeMagic(const MagicPtr& magic);
private:
	Unit* m_unit; // unit, that have this vector of magic
};
#endif // SPELLBOOK_H_