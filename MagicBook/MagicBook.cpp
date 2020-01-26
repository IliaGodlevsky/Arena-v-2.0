#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Interface/Interface.h"
#include "../Exceptions/BadincomingMagicException.h"

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
	if (!canCast<IManaCost*>(magic) || !canCast<IBuff*>(magic))
		throw BadIncomingMagicException("Incoming magic doesn't"
			" have needed interface. Bad class is MagicBook");
	else
		return true;
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

void MagicBook::setItemColor(const MagicPtr& magic)const
{
	IBuff* buff = nullptr;
	buff = DYNAMIC(IBuff*, magic);
	if (buff->isBuff())
		setColor(LIGHT_GREEN);
	else
		setColor(LIGHT_RED);
}

bool MagicBook::canCastAnySpell()const
{
	for (size_t i = 0; i < size(); i++)
		if (m_unit->isEnoughManaFor(operator[](i)))
			return true;
	return false;
}

void MagicBook::showShortInfo()const
{
	commentator.writeMessage("MagicBook: ");
	TemplateContainer<MagicPtr>::showShortInfo();
}

void MagicBook::takeNew(const MagicPtr& magic)
{
	if (itemHasPassedControl(magic) && !hasItem(magic))
		m_items.push_back(MagicPtr(magic->clone()));
}