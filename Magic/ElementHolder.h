#ifndef ELEM_HOLDER_H_
#define ELEM_HOLDER_H_

#include "Elements/ParamChangeElem.h"

class ElementHolder;
using ElemHolderPtr = std::unique_ptr<ElementHolder>;
using ElementsInit = std::initializer_list<ParamChangeElemPtr>;
using Elements = std::vector<ParamChangeElemPtr>;

class ElementHolder
{
public:
	ElementHolder() = default;
	ElementHolder(const ElementsInit& elements);
	ElementHolder(const ElementHolder& holder);
	void effectUnit(Unit& unit);
	void uneffectUnit(Unit& unit);
	const ParamChangeElemPtr& operator[](size_t i)const;
	size_t size()const;
	void takeElement(const ParamChangeElemPtr& element);
	bool isEqual(const ElementHolder& holder)const;
	~ElementHolder() = default;
private:
	Elements m_elements;
};
#endif
