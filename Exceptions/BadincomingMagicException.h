#ifndef BAD_INCOMING_MAGIC_H_
#define BAD_INCOMING_MAGIC_H_

#include "ArenaException.h"

class BadIncomingMagicException : public ArenaException
{
public:
	BadIncomingMagicException(const std::string& message);
	~BadIncomingMagicException() = default;
};
#endif
