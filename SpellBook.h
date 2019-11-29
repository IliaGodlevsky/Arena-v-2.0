#pragma once

#ifndef SPELLBOOK_H_
#define SPELLBOOK_H_

#include "Globals.h"

class SpellBook : public Spells
{
public:
	SpellBook(Unit& unit);
	bool CanCastAnySpell()const;
	void ShowFullInfo()const;
	void ShowShortInfo()const;
private:
	Unit* unit;
};
#endif