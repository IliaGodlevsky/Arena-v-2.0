#include "../Unit/Unit.h"
#include "../Magic/Magic.h"

#include "MagicOnMe.h"

MagicOnMe::MagicOnMe(Unit* unit)
	: m_unit(unit)
{

}

MagicOnMe::MagicOnMe(Unit* unit, const MagicOnMe& magicOnMe)
	: MagicOnMe(unit)
{
	for (size_t i = 0; i < magicOnMe.size(); i++)
		takeNew(magicOnMe[i]);
}

void MagicOnMe::makeExpire(size_t magicIndex)
{
	m_items[magicIndex]->setStartTime(Arena::getCurrentRound() - 
		m_items[magicIndex]->getDuration() - 1);
}

void MagicOnMe::takeOffExpired()
{
	for (size_t i = 0; i < m_items.size(); i++)
	{
		if (m_items[i]->isExpired(Arena::getCurrentRound()))
		{
			m_items[i]->uneffectUnit(*m_unit);
			m_items.erase(m_items.begin() + i);
			i--;
		}
	}
}

void MagicOnMe::takeNew(const MagicPtr& magic)
{
	expireIfFound(magic);
	m_items.push_back(MagicPtr(magic->clone()));
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
	std::cout << std::endl;
}