#include "../../../Magic/AttackMagic/AttackMagic.h"

#include "AttackMagicFactory.h"

AttackMagicFactory::AttackMagicFactory()
{
	m_items.push_back(MagicPtr(new AttackMagic("Magic arrow", 
		MAGIC_ARROW_MANA_COST, MAGIC_ARROW_DAMAGE)));
	m_items.push_back(MagicPtr(new AttackMagic("Magic hummer", 
		MAGIC_HUMMER_MANA_COST, MAGIC_HUMMER_DAMAGE)));
}