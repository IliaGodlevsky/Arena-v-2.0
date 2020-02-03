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

void MagicOnMe::makeExpire(MagicPtr& magic)
{
	auto temp = std::find_if(m_items.begin(), m_items.end(),
		[&](const MagicPtr& it) {return magic->isEqual(it); });
	IDispelable* dispel = DYNAMIC(IDispelable*, (*temp));
	IDuration* duration = DYNAMIC(IDuration*, (*temp));
	if (dispel->isDispelable())
	{
		duration->setStartTime(Arena::getCurrentRound() - 
			duration->getDuration() - 1);
	}
}

void MagicOnMe::takeOffExpired()
{
	auto expired = std::partition(m_items.begin(), m_items.end(),
		[](const MagicPtr& magic) {return !DYNAMIC(IDuration*, magic)->isExpired(); });
	std::for_each(expired, m_items.end(),
		[&](const MagicPtr& magic) { DYNAMIC(IUneffect*, magic)->uneffectUnit(*m_unit); });
	m_items.erase(expired, m_items.end());
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
	IBuff* buff = DYNAMIC(IBuff*, magic);
	if (buff != nullptr)
	{
		if (buff->isBuff())
			setColor(LIGHT_GREEN);
		else
			setColor(LIGHT_RED);
	}
	else
		setColor(LIGHT_CYAN);
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
			<< ": " << duration->getDurationRemained() << "> ";
	}
	setColor();
	std::cout << std::endl;
}