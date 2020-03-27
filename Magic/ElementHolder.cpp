#include <algorithm>

#include "../Unit/Unit.h"

#include "ElementHolder.h"

ElementHolder::ElementHolder(const ElementHolder& holder)
{
	for (size_t i = 0; i < holder.m_elements.size(); i++)
		takeElement(holder[i]);
}

ElementHolder::ElementHolder(const ElementsInitializerList& elements)
{
	for (auto i = elements.begin(); i != elements.end(); i++)
		takeElement(*i);
}

const ParamChangeElemPtr& ElementHolder::operator[](size_t i)const
{
	return m_elements.at(i);
}

size_t ElementHolder::size()const
{
	return m_elements.size();
}

void ElementHolder::effectUnit(Unit& unit)
{
	for (auto& element : m_elements)
		element->effectUnit(unit);
}

void ElementHolder::uneffectUnit(Unit& unit)
{
	for (auto& element : m_elements)
		element->uneffectUnit(unit);
}

void ElementHolder::takeElement(const ParamChangeElemPtr& element)
{
	m_elements.push_back(element->clone());
}

bool ElementHolder::isEqual(const ElementHolder& holder)const
{
	return std::is_permutation(m_elements.begin(),
		m_elements.end(), holder.m_elements.begin(),
		std::bind(&ParamChangeElem::isEqual, _1, _2));
}