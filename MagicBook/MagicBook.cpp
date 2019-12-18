#include "../Unit/Unit.h"
#include "../Magic/Magic.h"

#include "MagicBook.h"


MagicBook::MagicBook(Unit* unit)
	: m_unit(unit)
{

}

void MagicBook::magicList()const
{
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << i + 1 << ". ";
		operator[](i)->showShortInfo();
		std::cout << std::endl;
	}
}

bool MagicBook::canCastAnySpell()const
{
	bool can_cast = false;
	for (size_t i = 0; i < size(); i++)
	{
		if(m_unit->isEnoughManaFor(operator[](i)))
			can_cast = true;
	}
	return can_cast;
}

void MagicBook::showFullInfo()const
{
	for (size_t i = 0; i < size(); i++)
		operator[](i)->showFullInfo();
}

void MagicBook::showShortInfo()const
{
	std::cout << "MagicBook:\n";
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << i + 1 << ". ";
		operator[](i)->showShortInfo();
		std::cout << std::endl;
	}
}

void MagicBook::takeMagic(const MagicPtr& magic)
{
	if (nullptr != magic)
		push_back(MagicPtr(magic->clone()));
}