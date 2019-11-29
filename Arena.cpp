#include "Arena.h"

Arena::Arena()
{
	arena.resize(SetNumberOfUnits());
	SetArenaConsistance();
	FillArmory();
	FillSpells();
	FillSpells();
	// enter code with choosing magic and units
}

void Arena::FillSpells()
{
	spells.push_back(MagicPtr(new ArmorBuff		("Stone skin", 10, 2, 2)));
	spells.push_back(MagicPtr(new DamageBuff	("Rage", 10, 2, 5)));
	spells.push_back(MagicPtr(new ArmorDebuff	("Corruption", 12, 2, 2)));
	spells.push_back(MagicPtr(new DamageDebuff	("Weakness", 12, 2, 5)));
}

void Arena::FillArmory()
{
	
}

int Arena::CurrentRound()
{
	return round;
}

Arena& Arena::GetInstance()
{
	static Arena instance;
	return instance;
}

void Arena::TakeOfLosers()
{
	for (size_t i = 0; i < arena.size(); i++)
	{
		if (!arena[i]->IsAlive())
		{
			arena.erase(arena.begin() + i);
			i--;
		}
	}
}

bool Arena::GameOver()const
{
	return arena.size() == 1;
}

void Arena::CastStep()
{
	ShowUnits();
	magic_to_spell = arena[player_index_number]->ChooseMagicToCast();
	unit_to_cast = arena[player_index_number]->ChooseUnitToCast(magic_to_spell);
	arena[player_index_number]->Spell(*unit_to_cast, magic_to_spell);
}

void Arena::AttackStep()
{
	ShowUnits();
	unit_to_attack = arena[player_index_number]->ChooseUnitToAttack();
	arena[player_index_number]->Injure(*unit_to_attack);
}

void Arena::RewardKiller()
{
	if (!unit_to_cast->IsAlive())
		arena[player_index_number]->LevelUp();
}

void Arena::NextPlayer()
{
	player_index_number++;
	if (player_index_number >= arena.size())
	{
		player_index_number = 0;
		round++;
	}
}

void Arena::Scan()
{
	for (size_t i = 0; i < arena.size(); i++)
		arena[i]->Scan();
}