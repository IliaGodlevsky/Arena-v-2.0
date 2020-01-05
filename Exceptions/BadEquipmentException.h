#ifndef BAD_EQUIPMENT_EXCEPTION_H_
#define BAD_EQUIPMENT_EXCEPTION_H_

#include "ArenaException.h"

class BadEquipmentException : public ArenaException
{
public:
	BadEquipmentException(const std::string& message);
	~BadEquipmentException() = default;
};

#endif
