#include <iostream>

#include "Messager.h"

Messager::Messager():
	fout(new std::ofstream(stdout))
{
	
}

Messager::~Messager()
{
	delete fout;
}

void Messager::changeStream()
{
	//delete fout;
}

Messager& Messager::getIncstance()
{
	static Messager instance;
	return instance;
}

void Messager::writeMessage()const
{
	(*fout) << std::endl;
}