#ifndef EXPIREABLE_CONTAINER_H_
#define EXPIREABLE_CONTAINER_H_

#include <vector>

#include "../Timer/Timer.h"
#include "TemplateContainer.h"
#include "../Arena/Arena.h"

template<class T>
class ExpireableContainer : TemplateContainer<T>
{
public:
	virtual void takeOffExpired(int round) = 0;
	virtual void expire(size_t itemIndex);
	virtual void expireAll();
};

template <class T>
void ExpireableContainer<T>::expire(size_t index)
{
	m_items[index]->setStartTime(Arena::getCurrentRound() -
		m_items[index]->getDuration() - 1);
	takeOffExpired(Arena::getCurrentRound());
}

template <class T>
void ExpireableContainer<T>::expireAll()
{
	for (size_t i = 0; i < m_units.size(); i++)
		expire(i);
}
#endif
