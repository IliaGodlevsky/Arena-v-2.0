#include "ParamChangeElem.h"

ParamChangeElem::ParamChangeElem(int change)
	: m_change(change)
{

}

ParamChangeElem::operator int()const
{
	return m_change;
}