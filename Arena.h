#pragma once

#ifndef ARENA_H_
#define ARENA_H_

#include "UnitFactory.h"

class Arena
{
public:
	Arena();
	Arena(const UnitFactory* uf);
	
	~Arena();
private:
	void take_out_corpses();
	Magic* to_cast;
	Unit* to_spell;
	Unit* to_attack;
	Weapon* to_hit;
private:
	std::vector<Unit*> arena;
};

#endif