#ifndef EXPIREABLE_CONTAINER_H_
#define EXPIREABLE_CONTAINER_H_

#include <vector>

#include "TemplateContainer.h"
#include "../Arena/Arena.h"

template<class T>
class ExpireableContainer : public TemplateContainer<T>
{
public:
	virtual void takeOffExpired(int round) = 0;
	virtual void expire(size_t itemIndex);
	virtual void expireAll();
	virtual void makeExpire(size_t itemIndex)final;
	virtual ~ExpireableContainer() = default;
protected:
	virtual void expireIfFound(const T& item);
};

template <class T>
void ExpireableContainer<T>::makeExpire(size_t itemIndex)
{
	TemplateContainer<T>::m_items[itemIndex]->setStartTime(Arena::getCurrentRound() -
		TemplateContainer<T>::m_items[itemIndex]->getDuration() - 1);
}

template <class T>
void ExpireableContainer<T>::expire(size_t itemIndex)
{
	makeExpire(itemIndex);
	takeOffExpired(Arena::getCurrentRound());
}

template <class T>
void ExpireableContainer<T>::expireAll()
{
	for (size_t i = 0; i < TemplateContainer<T>::m_items.size(); i++)
		makeExpire(i);
	takeOffExpired(Arena::getCurrentRound());
}

template <class T>
void ExpireableContainer<T>::expireIfFound(const T& item)
{
	if (TemplateContainer<MagicPtr>::hasItem(magic))
	{
		index itemIndex = TemplateContainer<MagicPtr>::getItemIndex(magic);
		expire(itemIndex);
	}
}
#endif
