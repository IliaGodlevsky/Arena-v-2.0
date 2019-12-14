#include "SpellBook.h"
#include "Unit.h"

SpellBook::SpellBook(Unit* unit)
	: m_unit(unit)
{

}

void SpellBook::magicList()const
{
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << i + 1 << ". ";
		operator[](i)->showShortInfo();
		std::cout << std::endl;
	}
}

bool SpellBook::canCastAnySpell()const
{
	bool can_cast = false;
	for (size_t i = 0; i < size(); i++)
	{
		if(m_unit->isEnoughManaFor(operator[](i)))
			can_cast = true;
	}
	return can_cast;
}

void SpellBook::showFullInfo()const
{
	for (size_t i = 0; i < size(); i++)
		operator[](i)->showFullInfo();
}

void SpellBook::showShortInfo()const
{
	std::cout << "MagicBook:\n";
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << i + 1 << ". ";
		operator[](i)->showShortInfo();
		std::cout << std::endl;
	}
}

void SpellBook::takeMagic(const MagicPtr& magic)
{
	if (nullptr != magic)
		push_back(MagicPtr(magic->clone()));
}