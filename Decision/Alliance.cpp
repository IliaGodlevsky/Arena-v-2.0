#include "Alliance.h"

Alliance::Alliance()
{

}

void Alliance::takeAlly(const UnitPtr& ally)
{
	m_allies.push_back(ally);
	std::sort(m_allies.begin(), m_allies.end());
	m_allies.erase(std::unique(m_allies.begin(), m_allies.end()), 
		m_allies.end());
}

bool Alliance::isAlly(const Unit& unit)const
{
	for (size_t i = 0; i < m_allies.size(); i++)
		if (&unit == &(*m_allies[i]))
			return true;
	return false;
}