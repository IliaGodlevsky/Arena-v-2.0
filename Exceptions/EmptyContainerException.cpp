#include "EmptyContainerException.h"

EmptyContainerException::EmptyContainerException(const std::string& message)
	: ArenaException(message)
{

}