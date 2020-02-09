#include <fstream>
#include <chrono>
#include <thread>

#include "Globals.h"

void checkArgs(int& upper, int& lower)
{
	if (upper < lower)
		std::swap(upper, lower);
}

int inputNumber(const std::string& message,
	int upper, int lower)
{
	checkArgs(upper, lower);
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
	checkArgs(max, min);
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> 
		distributor(min, max); // [min,max]
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

int calculateDamageAbsorb(int armor, int damage)
{
	return static_cast<int>(std::floor(damage * 
		(1.0 - getPercentOfReduce(armor))));
}

double getPercentOfReduce(int armor)
{
	// The formula is taken from WarCraft 3
	constexpr double REDUCE_CONST = 0.06;
	const double numerator = static_cast<double>(armor * REDUCE_CONST);
	return numerator / (1.0 + numerator);
}

void exceptionMessage(std::exception& ex)
{
	std::cerr << "\a" << ex.what() << std::endl;
	system("pause");
}

void myTerminate()
{
	throw ArenaUninterseptedException("Arena has failed.\nPlease, try to fix the bugs and"
		" start it again.\nOr report about bug to godleevsky2015@gmail.com");
}

void signal(int milliseconds, int numberOfSignals)
{
	for (int i = 0; i < numberOfSignals; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
		std::cout << "\a";
	}
}

void setColor(TextColor text, TextColor background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
		(WORD)((background << 4) | text));
}