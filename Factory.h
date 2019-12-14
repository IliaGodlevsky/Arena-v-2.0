#pragma once

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Globals.h"

template <class T>
class Factory
{
public:
	Factory();
	virtual std::unique_ptr<T> createItem()const;
	virtual int getChanceOfCreation()const = 0;
	virtual ~Factory() = default;
protected:
	std::vector<std::unique_ptr<T>> m_items;
};

template<class T>
Factory<T>::Factory()
	: m_items(0)
{

}

template <class T>
std::unique_ptr<T> Factory<T>::createItem()const
{
	int itemIndex = randomNumber(m_items.size() - 1);
	return std::unique_ptr<T>(m_items[itemIndex]->clone());
}
#endif