#include <typeinfo>
#include <iostream>

#include "ArenaException.h"

ArenaException::ArenaException(const std::string& message)
	: m_message(message)
{

}

const char* ArenaException::what()const
{
	std::string temp = m_message;
	m_message = std::string(typeid(*this).name()) + " was occured. " + temp;
	return m_message.c_str();
}

ArenaException::~ArenaException()
{

}