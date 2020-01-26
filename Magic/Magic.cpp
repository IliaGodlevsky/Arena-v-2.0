#include "Magic.h"

#include "../Arena/Arena.h"
#include "../Unit/Unit.h"

Magic::Magic(std::string name)
	: m_name(name)
{

}

bool Magic::isEqual(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	return m_name == magic->m_name;
}

void Magic::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
}

void Magic::showShortInfo()const
{
	commentator.writeMessage(m_name);
}

const std::string& Magic::getName()const
{
	return m_name;
}
