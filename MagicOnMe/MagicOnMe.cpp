#include "../Unit/Unit.h"
#include "../Magic/Magic.h"

#include "MagicOnMe.h"

MagicOnMe::MagicOnMe(Unit* unit)
	: m_unit(unit)
{

}

void MagicOnMe::takeOfExpiredMagic(int round)
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

void MagicOnMe::takeMagic(const MagicPtr& magic)
{
	// number of spell that must be deleted 
	// from the spells that are on unit
	index magicIndex = 
		m_unit->m_magicOnMe.getMagicIndex(magic);
	if (magicIndex < size() && !empty())
		m_unit->m_magicOnMe.expireMagic(magicIndex);
	push_back(MagicPtr(magic->clone()));
}

size_t MagicOnMe::getMagicIndex(const MagicPtr& magic)const
{
	for (size_t i = 0; i < size(); i++)
		if (operator[](i)->isEqual(magic))
			return i;
	return size();
}

bool MagicOnMe::hasMagic(const MagicPtr& magic)const
{
	index magicIndex = m_unit->m_magicOnMe.getMagicIndex(magic);
	return (magicIndex < size() && !empty());
}

void MagicOnMe::expireMagic(size_t magicIndex)
{
	operator[](magicIndex)->uneffectUnit(*m_unit);
	erase(begin() + magicIndex);
}

void MagicOnMe::expireAllMagic()
{
	for (size_t i = 0; i < size(); i++)
	{
		expireMagic(i);
		i--;
	}
}

void MagicOnMe::showFullInfo()const
{
	for (size_t i = 0; i < size(); i++)
		operator[](i)->showFullInfo();
}

void MagicOnMe::showShortInfo()const
{
	std::cout << "Effect: ";
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << "<";
		std::cout << operator[](i)->getName();
		std::cout << "> ";
	}
}