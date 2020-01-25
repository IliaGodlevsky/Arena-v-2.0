#include "../../../Magic/AttackMagic/AttackMagic.h"
#include "../../../Magic/AttackMagic/AttackAndSilenceMagic.h"

#include "AttackMagicFactory.h"

AttackMagicFactory::AttackMagicFactory()
{
	m_items.push_back(MagicPtr(new AttackMagic("Magic arrow", 
		MAGIC_ARROW_MANA_COST, MAGIC_ARROW_DAMAGE)));
	m_items.push_back(MagicPtr(new AttackMagic("Magic hummer", 
		MAGIC_HUMMER_MANA_COST, MAGIC_HUMMER_DAMAGE)));
	m_items.push_back(MagicPtr(new AttackAndSilenceMagic("Silence fist", 
		SILENCE_FIST_MANA_COST, Timer(SILENCE_FIST_DURATION), SILENCE_FIST_DAMAGE)));
	m_items.push_back(MagicPtr(new AttackAndSilenceMagic("Fear", 
		FEAR_MANA_COST, Timer(FEAR_DURATION), FEAR_DAMAGE)));
}