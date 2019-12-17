#pragma once

#ifndef MAGICBOOK_H_
#define MAGICBOOK_H_

#include "../Globals/Globals.h"

class MagicBook : public Spells
{
public:
	MagicBook(Unit* unit);
	bool canCastAnySpell()const;
	void showFullInfo()const;
	void showShortInfo()const;
	void magicList()const;
	void takeMagic(const MagicPtr& magic);
private:
	Unit* m_unit; // unit, that have this vector of magic
};
#endif