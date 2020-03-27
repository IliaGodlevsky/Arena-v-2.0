#ifndef ELEM_HOLDER_H_
#define ELEM_HOLDER_H_

#include "Elements/ParamChangeElem.h"

class ElementHolder;
using ElemHolderPtr = std::unique_ptr<ElementHolder>;
using ElementsInitializerList = std::initializer_list<ParamChangeElemPtr>;
using MagicElements = std::vector<ParamChangeElemPtr>;

class ElementHolder
{
public:
	ElementHolder() = default;
	ElementHolder(const ElementsInitializerList& elements);
	ElementHolder(const ElementHolder& holder);
	void effectUnit(Unit& unit);
	void uneffectUnit(Unit& unit);
	const ParamChangeElemPtr& operator[](size_t i)const;
	size_t size()const;
	void takeElement(const ParamChangeElemPtr& element);
	bool isEqual(const ElementHolder& holder)const;
	~ElementHolder() = default;
private:
	MagicElements m_elements;
};
#endif
