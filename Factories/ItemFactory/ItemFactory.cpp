#include "ItemFactory.h"

ItemFactory::ItemFactory()
	: m_armorFactories(0),
	m_magicFactories(0),
	m_shieldFactories(0),
	m_weaponFactories(0),
	m_itemIndex(0)
{

}

MagicPtr ItemFactory::createMagic()const
{
	m_itemIndex = randomNumber(m_magicFactories.size() - 1);
	return m_magicFactories[m_itemIndex]->createItem();
}

WeaponPtr ItemFactory::createWeapon()const
{
	m_itemIndex = randomNumber(m_weaponFactories.size() - 1);
	return m_weaponFactories[m_itemIndex]->createItem();
}

ArmPtr ItemFactory::createArmor()const
{
	m_itemIndex = randomNumber(m_armorFactories.size() - 1);
	return m_armorFactories[m_itemIndex]->createItem();
}

ShieldPtr ItemFactory::createShield()const
{
	m_itemIndex = randomNumber(m_shieldFactories.size() - 1);
	return m_shieldFactories[m_itemIndex]->createItem();
}

ItemFactory::~ItemFactory()
{
	for (size_t i = 0; i < m_armorFactories.size(); i++)
		delete m_armorFactories[i];
	for (size_t i = 0; i < m_magicFactories.size(); i++)
		delete m_magicFactories[i];
	for (size_t i = 0; i < m_weaponFactories.size(); i++)
		delete m_weaponFactories[i];
	for (size_t i = 0; i < m_shieldFactories.size(); i++)
		delete m_shieldFactories[i];
}