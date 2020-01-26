#include <iostream>
#include <algorithm>

#include "Messager.h"

Messager::Messager()
{
	streams.push_back(&std::cout);
}

Messager::~Messager()
{
	for (size_t i = 0; i < streams.size(); i++)
		if (deleteStream(*streams[i]))
			i--;
}

void Messager::takeStream(std::ostream& os)
{
	deleteStream(os);
	streams.push_back(&os);
}

bool Messager::deleteStream(std::ostream& os)
{
	std::ofstream* o = nullptr;
	size_t streamSize = streams.size();
	for (size_t i = 0; i < streams.size();i++)
	{		
		if (streams[i] == &os)
		{
			if (o = dynamic_cast<std::ofstream*>(streams[i]))
				o->close();
			streams.erase(streams.begin() + i);
			i--;			
		}
	}
	return streamSize != streams.size();
}


Messager& Messager::getIncstance()
{
	static Messager instance;
	return instance;
}

void Messager::writeMessage()const
{
	
}