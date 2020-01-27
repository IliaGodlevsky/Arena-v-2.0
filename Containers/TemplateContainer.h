#ifndef TEMPL_CONTAINER_H_
#define TEMPL_CONTAINER_H_

#include <vector>
#include <iostream>

template <class T>
class TemplateContainer
{
public:
	TemplateContainer() = default;
	TemplateContainer(const TemplateContainer&) = delete;
	TemplateContainer(TemplateContainer&&) = default;
	TemplateContainer& operator=(const TemplateContainer&) = delete;
	TemplateContainer& operator=(TemplateContainer&&) = default;
	virtual bool itemHasPassedControl(const T& item)const = 0;
	virtual void takeNew(const T& item) = 0;
	size_t getItemIndex(const T& item)const;
	bool hasItem(const T& item)const;
	virtual const T& operator[](size_t t)const final;
	virtual void showShortInfo()const;
	virtual void setItemColor(const T& item)const = 0;
	virtual size_t size()const final;
	virtual ~TemplateContainer() = default;
protected:
	std::vector<T> m_items;
};

template <class T>
size_t TemplateContainer<T>::getItemIndex(const T& item)const
{
	for (size_t i = 0; i < m_items.size(); i++)
		if (m_items[i]->isEqual(item))
			return i;
	return size();
}

template <class T>
bool TemplateContainer<T>::hasItem(const T& item)const
{
	size_t itemIndex = getItemIndex(item);
	return (itemIndex < m_items.size() && !m_items.empty());
}

template <class T>
void TemplateContainer<T>::showShortInfo()const
{
	for (size_t i = 0; i < m_items.size(); i++)
	{
		setItemColor(m_items[i]);
		m_items[i]->showShortInfo();
	}
	setColor();
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
