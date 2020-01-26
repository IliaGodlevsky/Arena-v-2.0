#ifndef MESSAGER_H_
#define MESSAGER_H_

#include <fstream>
#include <vector>

class Messager
{
public:
	Messager(const Messager&) = delete;
	Messager(Messager&&) = delete;
	Messager& operator=(const Messager&) = delete;
	Messager& operator=(Messager&&) = delete;
	~Messager();
public:
	void takeStream(std::ostream& os);
	bool deleteStream(std::ostream& os);
	static Messager& getIncstance();
	template <typename T, typename ...Args>
	void writeMessage(const T& value, const Args&... args)const;
	template <typename T>
	void writeMessage(const T& value)const;
private:	
	void writeMessage()const;
private:
	Messager();
	std::vector<std::ostream*> streams;
};

template <typename T, typename ...Args>
void Messager::writeMessage(const T& value, const Args&... args)const
{
	for (size_t i = 0; i < streams.size(); i++)
		(*streams[i]) << value;
	writeMessage(args...);
}

template <typename T>
void Messager::writeMessage(const T& value)const
{
	for (size_t i = 0; i < streams.size(); i++)
		(*streams[i]) << value;
}
#endif