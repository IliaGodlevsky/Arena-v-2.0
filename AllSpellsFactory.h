#pragma once

#ifndef ALL_SPELLS_H_
#define ALL_SPELLS_H_

#include <initializer_list>
#include <random>

#include "Factory.h"

 //A class, that contains templates of abstract class Factory
template <class T>
class AllItemFactory
{
public:
	AllItemFactory(std::initializer_list<Factory<T>*> factList);
	T createItemFromFactory()const;
	~AllItemFactory();
private:
	int transformChanceToIndex(int chance)const;
	bool inBounds(int lower, int upper, int chance)const;
	int chance(int lowerBound, int upperBound)const;
private:
	static const int NO_MAGIC_LEFT = -1;
	int totalChances_ = 0;
	std::vector<int> chances_;
	std::vector<Factory<T>*> factories_;
};

template <class T>
AllItemFactory<T>::AllItemFactory(std::initializer_list<Factory<T>*> factList)
	: factories_(factList), chances_(factList.size())
{
	for (size_t i = 0; i < factList.size(); i++)
	{
		chances_[i] = factories_[i]->chance();
		totalChances_ += factories_[i]->chance();
	}
}

template <class T>
T AllItemFactory<T>::createItemFromFactory()const
{
	int ch = chance(0, totalChances_);
	int index = transformChanceToIndex(ch);
	if (index == NO_MAGIC_LEFT)
		return nullptr;
	Factory<T>* factory = factories_[index];
	return factories_[index]->createItem();
}

template <class T>
int AllItemFactory<T>::transformChanceToIndex(int chance)const
{
	int lower = 0, upper = 0;
	for (int i = 0; i < chances_.size(); i++)
	{
		upper += chances_[i];
		if (inBounds(lower, upper, chance))
			return i;
		else
			lower += chances_[i];
	}
	return NO_MAGIC_LEFT;
}

template <class T>
bool AllItemFactory<T>::inBounds(int lower, int upper, int chance)const
{
	if (chance >= lower && chance < upper)
		return true;
	else
		return false;
}

template <class T>
int AllItemFactory<T>::chance(int lowerBound, int upperBound)const
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int>
		distributor(lowerBound, upperBound);
	return distributor(generator);
}

template <class T>
AllItemFactory<T>::~AllItemFactory()
{
	for (size_t i = 0; i < factories_.size(); i++)
		delete factories_[i];
}

#endif