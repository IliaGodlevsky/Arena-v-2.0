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

void MagicOnMe::takeOffExpired(int round)
{
	for (size_t i = 0; i < m_items.size(); i++)
	{
		if (m_items[i]->isExpired(round))
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
		std::cout << "<" << (*this)[i]->getName() << ": ";
		std::cout << (*this)[i]->getStartTime() 
			+ (*this)[i]->getDuration() - Arena::getCurrentRound();
		std::cout << "> ";
	}
	std::cout << std::endl;
}