#include "../Unit/Unit.h"
#include "../Magic/Magic.h"

#include "MagicOnMe.h"

MagicOnMe::MagicOnMe(Unit* unit)
	: m_unit(unit)
{

}

void MagicOnMe::takeOffExpired(int round)
{
	for (size_t i = 0; i < TemplateContainer<MagicPtr>::m_items.size(); i++)
	{
		if (TemplateContainer<MagicPtr>::m_items[i]->isExpired(round))
		{
			TemplateContainer<MagicPtr>::m_items[i]->uneffectUnit(*m_unit);
			TemplateContainer<MagicPtr>::m_items.erase
			(TemplateContainer<MagicPtr>::m_items.begin() + i);
			i--;
		}
	}
}

void MagicOnMe::takeNew(const MagicPtr& magic)
{
	expireIfFound(magic);
	TemplateContainer<MagicPtr>::m_items.push_back(MagicPtr(magic->clone()));
}


void MagicOnMe::showShortInfo()const
{
	std::cout << "Effect: ";
	TemplateContainer<MagicPtr>::showShortInfo();
}