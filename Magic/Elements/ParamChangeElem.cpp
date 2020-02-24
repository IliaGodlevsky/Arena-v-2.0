#include "ParamChangeElem.h"

ParamChangeElem::ParamChangeElem(int change)
	: m_change(change)
{

}

ParamChangeElem::operator int()const
{
	return m_change;
}

bool ParamChangeElem::isEqual(const ParamChangeElemPtr& element)const
{
	if (!canCast<ParamChangeElem*>(element))
		return false;
	const auto temp = dCast<ParamChangeElem*>(element);
	return m_change == temp->m_change;
}