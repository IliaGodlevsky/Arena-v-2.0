#include <fstream>

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

std::vector<std::string> loadFromFile(const std::string& fileName)
{
	std::vector<std::string> lines;
	std::string line;
	std::ifstream fin(fileName);
	if (fin.fail())
	{
		std::cout << "\aCouldn't open file\n";
		return lines;
	}
	while (!fin.eof())
	{
		fin >> line;
		lines.push_back(line);
	}
	fin.close();
	return lines;
}

void exceptionMessage(std::exception& ex)
{
	std::cerr << ex.what() << std::endl;
	system("pause");
	exit(EXIT_FAILURE);
}