#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Exceptions/BadincomingMagicException.h"

#include "MagicOnMe.h"
#include "../Interface/Interface.h"
#include "../Expiring/Expiring.h"

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
	// Magic, that comes to this class, must have a definite interface
	if (!canCast<IDispelable*>(magic) || !canCast<Expiring*>(magic)
		|| !canCast<IUneffect*>(magic))
		throw BadIncomingMagicException("Incoming magic doesn't"
			" have needed interface. Bad class is MagicOnMe");
	else
		return true;
}

void MagicOnMe::makeExpire(MagicPtr& magic)
{
	const auto expireCandidate = std::find_if(m_items.begin(), m_items.end(),
		[&](const MagicPtr& it) {return magic->isEqual(it); });
	IDispelable* dispel = DYNAMIC(IDispelable*, (*expireCandidate));
	Expiring* expiring = DYNAMIC(Expiring*, (*expireCandidate));
	if (dispel->isDispelable())
		expiring->makeExpire();
}

void MagicOnMe::takeOffExpired()
{
	// sort magic to those, which has expired, and to those, that are acting
	const auto expiredMagics = std::partition(m_items.begin(), m_items.end(),
		[](const MagicPtr& magic) {return !DYNAMIC(IExpirable*, magic)->isExpired(); });
	std::for_each(expiredMagics, m_items.end(),
		[&](const MagicPtr& magic) { DYNAMIC(IUneffect*, magic)->uneffectUnit(*m_unit); });
	m_items.erase(expiredMagics, m_items.end());
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

void MagicOnMe::showItem(const MagicPtr& magic)const
{
	Expiring* expiring = DYNAMIC(Expiring*, magic);
	std::cout << "<" << magic->getName()
		<< ": " << expiring->getDurationRemained() << "> ";
}


void MagicOnMe::showShortInfo()const
{
	std::cout << "Effect: ";
	TemplateContainer<MagicPtr>::showShortInfo();
}