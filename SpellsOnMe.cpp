#include "SpellsOnMe.h"
#include "Unit.h"

SpellsOnMe::SpellsOnMe(Unit* unit)
	: unit(unit)
{

}

void SpellsOnMe::TakeOfExpired(int round)
{
	for (size_t i = 0; i < size(); i++)
	{
		if (operator[](i)->IsExpired(round))
		{
			operator[](i)->Uneffect(*unit);
			erase(begin() + i);
			i--;
		}
	}
}

void SpellsOnMe::TakeSpell(MagicPtr&& magic)
{
	// number of spell that must be deleted 
	// from the spells that are on unit
	size_t del = unit->on_me.HaveSpell(magic);
	unit->on_me.Expire(del);
	push_back(magic);
}

size_t SpellsOnMe::HaveSpell(const MagicPtr& spell)const
{
	for (size_t i = 0; i < size(); i++)
		if (operator[](i)->Equal(spell))
			return i;
	return size();
}

void SpellsOnMe::Expire(size_t spell_index)
{
	if (spell_index < size())
	{
		operator[](spell_index)->Uneffect(*unit);
		erase(begin() + spell_index);
	}
}

void SpellsOnMe::ExpireAllSpells()
{
	for (size_t i = 0; i < size(); i++)
	{
		Expire(i);
		i--;
	}
}

void SpellsOnMe::ShowFullInfo()const
{
	for (size_t i = 0; i < size(); i++)
		operator[](i)->ShowFullInfo();
}

void SpellsOnMe::ShowShortInfo()const
{
	for (size_t i = 0; i < size(); i++)
		operator[](i)->ShowShortInfo();
}