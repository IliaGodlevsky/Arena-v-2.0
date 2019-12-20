#include "../../../Magic/DebuffMagic/SilenceMagic.h"

#include "SilenceFactory.h"

SilenceFactory::SilenceFactory()
{
	m_items.push_back(MagicPtr(new SilenceMagic("Silence", SILENCE_MANA_COST, SILENCE_DURATION)));
}