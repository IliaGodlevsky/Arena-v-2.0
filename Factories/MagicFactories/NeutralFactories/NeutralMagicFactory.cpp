#include "NeutralFactory.h"

#include "../../../Magic/NeutralMagic/DispelMagic.h"

NeutralMagicFactory::NeutralMagicFactory()
{
	m_items.push_back(MagicPtr(new DispelMagic("Dispel", DISPEL_MANA_COST)));
}