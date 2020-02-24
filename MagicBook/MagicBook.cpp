#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Interface/Interface.h"
#include "../Exceptions/BadincomingMagicException.h"
#include "../Magic/AttackMagic/AttackMagic.h"

#include "MagicBook.h"

MagicBook::MagicBook(Unit* unit)
	: m_unit(unit)
{

}

MagicBook::MagicBook(Unit* unit, const MagicBook& book)
	: MagicBook(unit)
{
	for (size_t i = 0; i < book.size(); i++)
		takeNew(book[i]);
}

bool MagicBook::itemHasPassedControl(const MagicPtr& magic)const
{
	// magic must realise a definite interface
	if (!canCast<IManaCost*>(magic) || !canCast<IBuff*>(magic))
		throw BadIncomingMagicException("Incoming magic doesn't"
			" have needed interface. Bad class is MagicBook");
	else
		return true;
}

void MagicBook::showListOfMagic()const
{
	showInfo(&MagicBook::showShort);
}

void MagicBook::setItemColor(const MagicPtr& magic)const
{
	const auto attack = dCast<AttackMagic*>(magic);
	const auto buff = dCast<IBuff*>(magic);
	if (buff->isBuff())
		setColor(LIGHT_GREEN);
	else if (!buff->isBuff() && !attack)
		setColor(LIGHT_RED);
	else if (attack)
		setColor(YELLOW);
	
}

bool MagicBook::canCastAnySpell()const
{
	return std::any_of(m_items.begin(), m_items.end(),
		std::bind(&Unit::isEnoughManaFor, m_unit, _1));
}

void MagicBook::showFullInfo()const
{
	showInfo(&MagicBook::showFull);
}

void MagicBook::takeNew(const MagicPtr& magic)
{
	if (itemHasPassedControl(magic) && !hasItem(magic))
		m_items.push_back(MagicPtr(magic->clone()));
}

void MagicBook::showInfo(const ShowMethod& show)const
{
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << i + 1 << ". ";
		(this->*show)(operator[](i));
	}
}

void MagicBook::showFull(const MagicPtr& magic)const
{
	magic->showFullInfo();
}

void MagicBook::showShort(const MagicPtr& magic)const
{
	magic->showShortInfo();
	std::cout << std::endl;
}