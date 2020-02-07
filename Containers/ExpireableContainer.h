#ifndef EXPIREABLE_CONTAINER_H_
#define EXPIREABLE_CONTAINER_H_

#include "TemplateContainer.h"
#include "../Arena/Arena.h"
#include "../Expiring/Expiring.h"

template<class T>
class ExpireableContainer : public TemplateContainer<T>
{
public:
	virtual void takeOffExpired() = 0;
	virtual void expire(T& item);
	virtual void expireAll();
	virtual void makeExpire(T& item) = 0;
	virtual ~ExpireableContainer() = default;
protected:
	virtual void expireIfFound(const T& item);
};

template <class T>
void ExpireableContainer<T>::expire(T& item)
{
	makeExpire(item);
	takeOffExpired();
}

template <class T>
void ExpireableContainer<T>::expireAll()
{
	std::for_each(TemplateContainer<T>::m_items.begin(),
		TemplateContainer<T>::m_items.end(),
		[&](T& item) {this->makeExpire(item); });
	takeOffExpired();
}

template <class T>
void ExpireableContainer<T>::expireIfFound(const T& item)
{
	if (TemplateContainer<T>::hasItem(item))
	{
		auto temp = std::find_if(TemplateContainer<T>::m_items.begin(),
			TemplateContainer<T>::m_items.end(), 
			[&](const T& it) {return item->isEqual(it); });
		expire(*temp);
	}
}
#endif
