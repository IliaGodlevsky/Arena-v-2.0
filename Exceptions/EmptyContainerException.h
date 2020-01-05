#ifndef EMPTY_CONTAINER_H_
#define EMPTY_CONTAINER_H_

#include "ArenaException.h"

class EmptyContainerException : public ArenaException
{
public:
	EmptyContainerException(const std::string& message);
	~EmptyContainerException() = default;
};


#endif
