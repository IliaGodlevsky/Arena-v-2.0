#pragma once

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Globals.h"
#include "Magic.h"

// A class template
// Each factory makes the same, so I decided to 
// create a template abstract factory, that will
// create any class, that will be as a paramtre
// of a template
template <class T>
class Factory
{
public:
	Factory();
	virtual T createItem()const final;
	virtual int chance()const = 0;
	virtual ~Factory();
protected:
	std::vector<T> items;
};

template<class T>
Factory<T>::Factory()
	: items(0)
{

}

template <class T>
T Factory<T>::createItem()const
{
	int index = randomIndex(items.size());
	return T(items[index]);
}
template <> inline // inline!!
MagicPtr Factory<MagicPtr>::createItem()const
{
	int index = randomIndex(items.size());
	return MagicPtr(items[index]->Clone());
}

template <class T>
Factory<T>::~Factory()
{
	for (size_t i = 0; i < items.size(); i++)
		delete items[i];
}

// unique_ptr doesn't need delete
template <> inline
Factory<MagicPtr>::~Factory()
{

}
#endif