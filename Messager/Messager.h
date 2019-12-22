#ifndef MESSAGER_H_
#define MESSAGER_H_

#include <fstream>

class Messager
{
public:
	Messager(const Messager&) = delete;
	Messager(Messager&&) = delete;
	Messager& operator=(const Messager&) = delete;
	Messager& operator=(Messager&&) = delete;
	~Messager();
public:
	static Messager& getIncstance();
	void changeStream();
	template <typename T, typename ...Args>
	void writeMessage(const T& value, const Args&... args)const;
private:
	template <typename T>
	void writeMessage(const T& value)const;
	void writeMessage()const;
private:
	Messager();
	std::ofstream* fout;
};

template <typename T, typename ...Args>
void Messager::writeMessage(const T& value, const Args&... args)const
{
	(*fout) << value;
	writeMessage(args...);
}

template <typename T>
void Messager::writeMessage(const T& value)const
{
	(*fout) << value;
}
#endif