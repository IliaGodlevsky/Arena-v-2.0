#include "Globals.h"

int inputNumber(const std::string& message,
	int upper, int lower)
{
	int choice;
	std::cout << message;
	std::cin >> choice;
	while (isError(choice, upper, lower))
	{
		eatLine();
		std::cout << message;
		std::cin >> choice;
	}
	return choice;
}

bool isError(int choice, int upper, int lower)
{
	return !std::cin
		|| choice > upper
		|| choice < lower;
}

void eatLine()
{
	std::cin.clear();
	while (!iscntrl(std::cin.get()))
		continue;
}

int randomNumber(int max, int min) 
{ 
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> 
		distributor(min, max);
	return distributor(generator);
}