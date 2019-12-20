#include "../../../Magic/AttackMagic/PoisonAndAttackMagic.h"

#include "PoisonAndAttackMagicFactory.h"

PoisonAndAttackMagicFactory::PoisonAndAttackMagicFactory()
{
	m_items.push_back(MagicPtr(new PoisonAndAttackMagic("Poison knife",
		POISON_KNIFE_MANA_COST, POISON_KNIFE_DURATION, POISON_KNIFE_DAMAGE, POISON_KNIFE_DEGENERATION)));
	m_items.push_back(MagicPtr(new PoisonAndAttackMagic("Poison bite", 
		POISON_BITE_MANA_COST, POISON_BITE_DURATION, POISON_BITE_DAMAGE, POISON_BITE_DEGENERATION)));

}