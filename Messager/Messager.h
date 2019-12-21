#ifndef MESSAGER_H_
#define MESSAGER_H_

#include <fstream>
#include <initializer_list>
#include <string>

using MessageList = std::initializer_list<std::string>;

class Messager
{
public:
	Messager(const Messager&) = delete;
	Messager(Messager&&) = delete;
	Messager& operator=(const Messager&) = delete;
	Messager& operator=(Messager&&) = delete;
public:
	static Messager& getIncstance();
	void changeStream();
	void writeMessage(MessageList messageList)const;
private:
	Messager();
	~Messager();
	std::ofstream* fout;
};
#endif