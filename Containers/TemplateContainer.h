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
	bool hasItem(const T& item)const;
	virtual const T& operator[](size_t t)const final;
	virtual void showShortInfo()const;
	virtual void setItemColor(const T& item)const = 0;
	virtual size_t size()const final;	
	virtual ~TemplateContainer() = default;
protected:
	virtual void showItem(const T& item)const;
	std::vector<T> m_items;
};

template <class T>
bool TemplateContainer<T>::hasItem(const T& item)const
{
	return std::find_if(m_items.begin(), m_items.end(),
		[&](const T& it) {return item->isEqual(it); }) != m_items.end();
}

template <class T>
void TemplateContainer<T>::showShortInfo()const
{
	for (size_t i = 0; i < m_items.size(); i++)
	{
		setItemColor(m_items[i]);
		if (i % 2 == 0 && i != 0)
			std::cout << std::endl << "\t";
		showItem(m_items[i]);
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
void TemplateContainer<T>::showItem(const T& item)const
{
	item->showShortInfo();
}

template <class T>
const T& TemplateContainer<T>::operator[](size_t t)const
{
	return m_items.at(t);
}
#endif
