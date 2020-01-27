#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Exceptions/BadincomingMagicException.h"

#include "MagicOnMe.h"
#include "../Interface/Interface.h"

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

bool MagicOnMe::itemHasPassedControl(const MagicPtr& magic)const
{
	if (!canCast<IDispelable*>(magic) || !canCast<IDuration*>(magic)
		|| !canCast<IUneffect*>(magic))
		throw BadIncomingMagicException("Incoming magic doesn't"
			" have needed interface. Bad class is MagicOnMe");
	else
		return true;
}

void MagicOnMe::makeExpire(size_t magicIndex)
{
	IDispelable* dispel = DYNAMIC(IDispelable*, m_items[magicIndex]);
	IDuration* duration = DYNAMIC(IDuration*, m_items[magicIndex]);
	if (dispel->isDispelable())
	{
		duration->setStartTime(Arena::getCurrentRound() - 
			duration->getDuration() - 1);
	}
}

void MagicOnMe::takeOffExpired()
{
	IDuration* duration = nullptr;
	IUneffect* uneffect = nullptr;
	for (size_t i = 0; i < m_items.size(); i++)
	{
		duration = DYNAMIC(IDuration*, m_items[i]);
		uneffect = DYNAMIC(IUneffect*, m_items[i]);
		if (duration->isExpired())
		{
			uneffect->uneffectUnit(*m_unit);
			m_items.erase(m_items.begin() + i);
			i--;
		}
	}
}

void MagicOnMe::takeNew(const MagicPtr& magic)
{
	if (itemHasPassedControl(magic))
	{
		expireIfFound(magic);
		m_items.push_back(MagicPtr(magic->clone()));
	}
}

void MagicOnMe::setItemColor(const MagicPtr& magic)const
{
	IBuff* buff = nullptr;
	buff = DYNAMIC(IBuff*, magic);
	if (buff != nullptr)
	{
		if (buff->isBuff())
			setColor(LIGHT_GREEN);
		else
			setColor(LIGHT_RED);
	}
	else
		setColor(YELLOW);
}


void MagicOnMe::showShortInfo()const
{
	IDuration* duration = nullptr;
	std::cout << "Effect: ";
	for (size_t i = 0; i < size(); i++)
	{
		duration = DYNAMIC(IDuration*, operator[](i));
		setItemColor(operator[](i));
		if (i % 2 == 0 && i != 0)
			std::cout << std::endl << "\t";
		std::cout << "<" << operator[](i)->getName() 
			<< ": " << duration->getStartTime()
			+ duration->getDuration() - Arena::getCurrentRound() << "> ";
	}
	setColor();
	std::cout << std::endl;
}