#pragma once

#ifndef MAGIC_ON_ME
#define MAGIC_ON_ME

#include "../Globals/Globals.h"

class MagicOnMe : public Spells
{
public:
	MagicOnMe(Unit* unit);
	void takeOfExpiredMagic(int round);
	size_t getMagicIndex(const MagicPtr& magic)const;
	void expireMagic(size_t magicIndex);
	void expireAllMagic();
	void takeMagic(const MagicPtr& magic);
	void showFullInfo()const;
	void showShortInfo()const;
private:
	Unit* m_unit; // unit, that have this vector of spells
};
#endif