#ifndef FACTORY_H_
#define FACTORY_H_

#include <type_traits>

#include "../Magic/Magic.h"
#include "../Armor/Armor.h"
#include "../Weapon/Weapon.h"
#include "../Shield/Shield.h"

template <class T>
using Items = std::vector<std::unique_ptr<T>>;

template <class T>
class Factory
{
public:
	Factory();
	virtual std::unique_ptr<T> createItem()const;
	virtual ~Factory() = default;
protected:
	Items<T> m_items;
};

template<class T>
Factory<T>::Factory()
	: m_items(0)
{
	static_assert(
		std::is_base_of<Armor, T>::value
		|| std::is_base_of<Weapon, T>::value
		|| std::is_base_of<Magic, T>::value
		|| std::is_base_of<Shield, T>::value, 
		"Bad template argument: Armor, Weapon, Magic or Shield are allowed only\n");
}

template <class T>
std::unique_ptr<T> Factory<T>::createItem()const
{
	index itemIndex = randomNumber(m_items.size() - 1);
	return std::unique_ptr<T>(m_items[itemIndex]->clone());
}

#endif