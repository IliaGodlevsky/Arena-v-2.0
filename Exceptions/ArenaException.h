#ifndef ARENA_EXCEPTION_H_
#define ARENA_EXCEPTION_H_

#include <exception>
#include <string>

class ArenaException : public std::exception
{
public:
	ArenaException(const std::string& message);
	const char* what()const;
	virtual ~ArenaException() = 0;
private:
	mutable std::string m_message;
};

#endif