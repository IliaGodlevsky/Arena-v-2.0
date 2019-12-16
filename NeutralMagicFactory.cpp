#include "NeutralMagicFactory.h"
#include "NeutralMagic.h"

NeutralMagicFactory::NeutralMagicFactory()
{
	m_items.push_back(MagicPtr(new Dispel("Dispel", DISPEL_MANA_COST)));
}

int NeutralMagicFactory::getChanceOfCreation()const
{
	return 10;
}