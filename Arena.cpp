#include "Arena.h"

Arena::Arena()
{
	human = new HumanDecision(arena);
	computer = new ComputerDecision(arena);
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
	armors.push_back(new WizardCloak(3, { 4,4,0 }));
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
		if (arena[i]->health.IsDead())
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

void Arena::GameCycle()
{
	UnitPtr unit_to_attack = nullptr;
	UnitPtr unit_to_cast = nullptr;
	MagicPtr magic_to_spell = nullptr;
	for (size_t i = 0; i < arena.size(); i++)
	{
		arena[i]->ShowUnitName();
		magic_to_spell = decisions[i]->ChooseMagicToCast(arena[i]);
		unit_to_cast = decisions[i]->ChooseUnitToCast(arena[i], magic_to_spell);
		arena[i]->Spell(unit_to_cast, magic_to_spell);
		TakeOfLosers();
		unit_to_attack = decisions[i]->ChooseUnitToAttack(arena[i]);
		arena[i]->Injure(unit_to_attack);
		TakeOfLosers();
	}
}