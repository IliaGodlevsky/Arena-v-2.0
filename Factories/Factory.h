#ifndef FACTORY_H_
#define FACTORY_H_

#include "../Globals/Globals.h"

template <class T>
using TPtr = std::unique_ptr<T>;

template <class T>
using Items = std::vector<TPtr<T>>;

template <class T>
class Factory
{
public:
	Factory();
	virtual TPtr<T> createItem()const;
	virtual int getChanceOfCreation()const = 0;
	virtual ~Factory() = default;
protected:
	Items<T> m_items;
};

template<class T>
Factory<T>::Factory()
	: m_items(0)
{

}

template <class T>
TPtr<T> Factory<T>::createItem()const
{
	index itemIndex = randomNumber(m_items.size() - 1);
	return TPtr<T>(m_items[itemIndex]->clone());
}

#endif