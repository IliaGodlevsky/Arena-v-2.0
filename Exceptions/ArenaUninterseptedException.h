#ifndef ARENA_UNINTERSEPTED_EXCEPTION_H_
#define ARENA_UNINTERSEPTED_EXCEPTION_H_

#include "ArenaException.h"

class ArenaUninterseptedException : public ArenaException
{
public:
	ArenaUninterseptedException(const std::string message);
	~ArenaUninterseptedException() = default;
};
#endif
