#include "ParamChangeMagic.h"
#include "../Unit/Unit.h"

ParamChangeMagic::ParamChangeMagic(std::string name, int manaCost,
	Time time, const ElementsInit& holder)
	: FreeParamChangeMagic(name, time, holder), IManaCost(manaCost)
{

}

ParamChangeMagic::ParamChangeMagic(std::string name, int manaCost,
	Time time, const ElementHolder& holder)
	: FreeParamChangeMagic(name, time, holder), IManaCost(manaCost)
{

}

bool ParamChangeMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<ParamChangeMagic*>(magic))
		return false;
	ParamChangeMagic* temp = DYNAMIC(ParamChangeMagic*, magic);
	return FreeParamChangeMagic::isEqual(magic)
		&& m_manaCost == temp->m_manaCost;
}

void ParamChangeMagic::showFullInfo()const
{
	Magic::showFullInfo();
	for (size_t i = 0; i < m_elemHolder.size(); i++)
	{
		m_elemHolder[i]->showInfo();
		std::cout << " for " << getDuration() << " rounds\n";
	}
}

void ParamChangeMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}