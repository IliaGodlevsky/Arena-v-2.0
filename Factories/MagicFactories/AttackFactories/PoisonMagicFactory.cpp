#include "../../../Magic/AttackMagic/PoisonMagic.h"

#include "PoisonMagicFactory.h"

PoisonMagicFactory::PoisonMagicFactory()
{
	m_items.push_back(MagicPtr(new PoisonMagic("Illness", 
		ILLNESS_MANA_COST, Timer(ILLNESS_DURATION), ILLNESS_DEGENERATION)));
	m_items.push_back(MagicPtr(new PoisonMagic("Bleeding", 
		BLEEDING_MANA_COST, Timer(BLEEDING_DURATION), BLEEDING_DEGENERATION)));
	m_items.push_back(MagicPtr(new PoisonMagic("Parasite", 
		PARASITE_MANA_COST, Timer(PARASITE_DURATION), PARASITE_DEGENERATION)));
}