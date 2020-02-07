#include "Interface.h"

IManaCost::IManaCost(int manaCost)
	: m_manaCost(manaCost)
{

}

int IManaCost::getCost()const
{
	return m_manaCost;
}