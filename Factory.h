#pragma once

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Globals.h"
#include "Magic.h"

// A class template
// Each factory makes the same, so I decided to 
// create a template abstract factory, that will
// create any class, that will be as a parametre
// of a template
template <class T>
class Factory
{
	using ItemPtr = std::unique_ptr<T>;
public:
	Factory();
	virtual ItemPtr createItem()const final;
	virtual int getChanceOfCreation()const = 0;
	virtual ~Factory() = default;
protected:
	std::vector<ItemPtr> m_items;
};

template<class T>
Factory<T>::Factory()
	: m_items(0)
{

}

template <class T>
Factory<T>::ItemPtr Factory<T>::createItem()const
{
	int itemIndex = randomIndex(m_items.size());
	return ItemPtr(m_items[itemIndex]->clone());
}
#endif