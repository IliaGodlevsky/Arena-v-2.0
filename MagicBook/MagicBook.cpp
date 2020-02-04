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
	AttackMagic* attack = DYNAMIC(AttackMagic*, magic);
	IBuff* buff = DYNAMIC(IBuff*, magic);
	if (buff->isBuff())
		setColor(LIGHT_GREEN);
	else if (!buff->isBuff() && nullptr == attack)
		setColor(LIGHT_RED);
	else if (nullptr != attack)
		setColor(YELLOW);
	
}

bool MagicBook::canCastAnySpell()const
{
	return std::any_of(m_items.begin(), m_items.end(),
		[&](const MagicPtr& magic) {return m_unit->isEnoughManaFor(magic); });
}

void MagicBook::showShortInfo()const
{
	std::cout << "MagicBook: ";
	TemplateContainer<MagicPtr>::showShortInfo();
}

void MagicBook::showFullInfo()const
{
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << i + 1 << ". ";
		operator[](i)->showFullInfo();
	}
}

void MagicBook::takeNew(const MagicPtr& magic)
{
	if (itemHasPassedControl(magic) && !hasItem(magic))
		m_items.push_back(MagicPtr(magic->clone()));
}