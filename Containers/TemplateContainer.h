#ifndef TEMPL_CONTAINER_H_
#define TEMPL_CONTAINER_H_

#include <vector>
#include <iostream>

template <class T>
class TemplateContainer
{
public:
	virtual void takeNew(const T& item) = 0;
	size_t getItemIndex(const T& item)const;
	bool hasItem(const T& item)const;
	virtual const T& operator[](size_t t)const final;
	virtual void showShortInfo()const;
	virtual size_t size()const final;
protected:
	std::vector<T> m_items;
};

template <class T>
size_t TemplateContainer<T>::getItemIndex(const T& item)const
{
	for (size_t i = 0; i < m_items.size(); i++)
		if (m_items[i]->isEqual(item))
			return i;
	return m_items.size();
}

template <class T>
bool TemplateContainer<T>::hasItem(const T& item)const
{
	size_t magicIndex = getItemIndex(item);
	return (magicIndex < m_items.size() && !m_items.empty());
}

template <class T>
void TemplateContainer<T>::showShortInfo()const
{
	for (size_t i = 0; i < m_items.size(); i++)
		m_items[i]->showShortInfo();
	std::cout << std::endl;
}

template <class T>
size_t TemplateContainer<T>::size()const
{
	return m_items.size();
}
template <class T>
const T& TemplateContainer<T>::operator[](size_t t)const
{
	return m_items[t];
}
#endif
