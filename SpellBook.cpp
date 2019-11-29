
#include "SpellBook.h"
#include "Unit.h"

SpellBook::SpellBook(Unit* unit)
	: unit(unit)
{

}

bool SpellBook::CanCastAnySpell()const
{
	bool can_cast = false;
	for (size_t i = 0; i < size(); i++)
	{
		if(unit->EnoughManaFor(operator[](i)))
			can_cast = true;
	}
	return can_cast;
}

void SpellBook::ShowFullInfo()const
{
	for (size_t i = 0; i < size(); i++)
		operator[](i)->ShowFullInfo();
}

void SpellBook::ShowShortInfo()const
{
	for (size_t i = 0; i < size(); i++)
		operator[](i)->ShowShortInfo();
}