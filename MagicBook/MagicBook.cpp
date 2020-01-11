#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Interface/Interface.h"

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
		throw ("Magic book exception");
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

bool MagicBook::canCastAnySpell()const
{
	for (size_t i = 0; i < size(); i++)
		if (m_unit->isEnoughManaFor(operator[](i)))
			return true;
	return false && !m_items.empty();
}

void MagicBook::showShortInfo()const
{
	std::cout << "MagicBook: ";
	TemplateContainer<MagicPtr>::showShortInfo();
}

void MagicBook::takeNew(const MagicPtr& magic)
{
	if (itemHasPassedControl(magic))
		m_items.push_back(MagicPtr(magic->clone()));
}