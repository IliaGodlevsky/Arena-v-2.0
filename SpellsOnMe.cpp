#include "SpellsOnMe.h"
#include "Unit.h"

#include <iostream>

SpellsOnMe::SpellsOnMe(Unit* unit)
	: m_unit(unit)
{

}

void SpellsOnMe::takeOfExpiredMagic(int round)
{
	for (size_t i = 0; i < size(); i++)
	{
		if (operator[](i)->isExpired(round))
		{
			operator[](i)->uneffectUnit(*m_unit);
			erase(begin() + i);
			i--;
		}
	}
}

void SpellsOnMe::takeMagic(const MagicPtr& magic)
{
	// number of spell that must be deleted 
	// from the spells that are on unit
	size_t magicIndex = 
		m_unit->m_magicOnMe.getMagicIndex(magic);
	if (magicIndex < size() && !empty())
		m_unit->m_magicOnMe.expireMagic(magicIndex);
	push_back(MagicPtr(magic->clone()));
}

size_t SpellsOnMe::getMagicIndex(const MagicPtr& magic)const
{
	for (size_t i = 0; i < size(); i++)
		if (operator[](i)->isEqual(magic))
			return i;
	return size();
}

void SpellsOnMe::expireMagic(size_t magicIndex)
{
	operator[](magicIndex)->uneffectUnit(*m_unit);
	erase(begin() + magicIndex);
}

void SpellsOnMe::expireAllMagic()
{
	for (size_t i = 0; i < size(); i++)
	{
		expireMagic(i);
		i--;
	}
}

void SpellsOnMe::showFullInfo()const
{
	for (size_t i = 0; i < size(); i++)
		operator[](i)->showFullInfo();
}

void SpellsOnMe::showShortInfo()const
{
	std::cout << "Effect: ";
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << "<";
		std::cout << operator[](i)->getName();
		std::cout << ">";
	}
}