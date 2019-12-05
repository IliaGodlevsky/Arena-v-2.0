#pragma once

#ifndef ALL_SPELLS_H_
#define ALL_SPELLS_H_

#include <initializer_list>
#include <random>

#include "Factory.h"

template <class T>
class AllItemFactory
{
public:
	AllItemFactory(std::initializer_list<Factory<T>*> factList);
	std::unique_ptr<T> createItemFromFactory()const;
	~AllItemFactory() = default;
private:
	size_t transformChanceToIndex(int chance)const;
	bool isInBounds(int lower, int upper, int chance)const;
	int countChance(int lowerBound, int upperBound)const;
private:
	int m_totalChances = 0;
	std::vector<int> m_chancesOfCreation;
	std::vector<Factory<T>*> m_factories;
};

template <class T>
AllItemFactory<T>::AllItemFactory(std::initializer_list<Factory<T>*> factList)
	: m_factories(factList), m_chancesOfCreation(factList.size())
{
	for (size_t i = 0; i < factList.size(); i++)
	{
		m_chancesOfCreation[i] = m_factories[i]->getChanceOfCreation();
		m_totalChances += m_factories[i]->getChanceOfCreation();
	}
}

template <class T>
std::unique_ptr<T> AllItemFactory<T>::createItemFromFactory()const
{
	int chance = countChance(0, m_totalChances);
	int itemIndex = transformChanceToIndex(chance);
	if (itemIndex == m_chancesOfCreation.size())
		return nullptr;
	return m_factories[itemIndex]->createItem();
}

template <class T>
size_t AllItemFactory<T>::transformChanceToIndex(int chance)const
{
	int lower = 0, upper = 0;
	for (size_t i = 0; i < m_chancesOfCreation.size(); i++)
	{
		upper += m_chancesOfCreation[i];
		if (isInBounds(lower, upper, chance))
			return i;
		else
			lower += m_chancesOfCreation[i];
	}
	return m_chancesOfCreation.size();
}

template <class T>
bool AllItemFactory<T>::isInBounds(int lower, int upper, int chance)const
{
	if (chance >= lower && chance < upper)
		return true;
	else
		return false;
}

template <class T>
int AllItemFactory<T>::countChance(int lowerBound, int upperBound)const
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int>
		distributor(lowerBound, upperBound);
	return distributor(generator);
}

#endif