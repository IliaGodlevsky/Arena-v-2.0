#include "../../Armor/Armor.h"

#include "ArmorFactory.h"

ArmorFactory::ArmorFactory()
{
	m_items.push_back(ArmPtr(new Armor("Lether armor", LETHER_ARMOR_DEF)));
	m_items.push_back(ArmPtr(new Armor("Chain mail", CHAIN_MAIL_DEF)));
}