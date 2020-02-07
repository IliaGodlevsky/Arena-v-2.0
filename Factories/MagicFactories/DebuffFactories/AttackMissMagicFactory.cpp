#include "../../../Magic/DebuffMagic/AttackMissChanceMagic.h"
#include "../../../PossibilityCounter/PosibilityCounter.h"
#include "AttackMissMagicFactory.h"

AttackMissMagicFactory::AttackMissMagicFactory()
{
	m_items.push_back(MagicPtr(new AttackMissChanceMagic("Disorientation", 
		DISORIENTATION_CHANCE, DISORIENTATION_MANA_COST, DISORIENTATION_DURATION)));
	m_items.push_back(MagicPtr(new AttackMissChanceMagic("Oblivion", OBLIVION_CHANCE, OBLIVION_MANA_COST, 
		OBLIVION_DURATION)));
}