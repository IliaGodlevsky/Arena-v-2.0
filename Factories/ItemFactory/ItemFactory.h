#ifndef ITEM_FACTORY_H_
#define ITEM_FACTORY_H_

#include "../Factory.h"

class ItemFactory
{
public:
	ItemFactory();
	virtual ~ItemFactory();
	virtual MagicPtr createMagic()const final;
	virtual WeaponPtr createWeapon()const final;
	virtual ArmPtr createArmor()const final;
	virtual ShieldPtr createShield()const final;
protected:
	std::vector<Factory<Magic>*> m_magicFactories;
	std::vector<Factory<Weapon>*> m_weaponFactories;
	std::vector<Factory<Armor>*> m_armorFactories;
	std::vector<Factory<Shield>*> m_shieldFactories;
	mutable index m_itemIndex;
};
#endif