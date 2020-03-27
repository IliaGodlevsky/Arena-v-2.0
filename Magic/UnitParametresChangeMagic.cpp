#include "UnitParametresChangeMagic.h"
#include "../Unit/Unit.h"

UnitParametresChangeMagic::UnitParametresChangeMagic(std::string name, int manaCost,
	Time time, const ElementsInitializerList& holder)
	: ManaFreeUnitParametresChangeMagic(name, time, holder), IManaCost(manaCost)
{

}

UnitParametresChangeMagic::UnitParametresChangeMagic(std::string name, int manaCost,
	Time time, const ElementHolder& holder)
	: ManaFreeUnitParametresChangeMagic(name, time, holder), IManaCost(manaCost)
{

}

bool UnitParametresChangeMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<UnitParametresChangeMagic*>(magic))
		return false;
	const auto temp = dCast<UnitParametresChangeMagic*>(magic);
	return ManaFreeUnitParametresChangeMagic::isEqual(magic)
		&& m_manaCost == temp->m_manaCost;
}

void UnitParametresChangeMagic::showFullInfo()const
{
	Magic::showFullInfo();
	for (size_t i = 0; i < m_elemHolder.size(); i++)
	{
		m_elemHolder[i]->showInfo();
		std::cout << " for " << getDuration() << " rounds\n";
	}
}

void UnitParametresChangeMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}