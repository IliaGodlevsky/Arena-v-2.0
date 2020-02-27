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

Strings loadFromFile(const std::string& fileName)
{
	Strings lines;
	std::string line;
	std::ifstream fin(fileName);
	if (fin.fail())
	{
		std::cout << "\aCouldn't open file.\nUse reserved unit names\n";
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

void signal(Signals milliseconds, Signals numberOfSignals)
{
	for (int i = 0; i < static_cast<int>(numberOfSignals); i++)
	{
		std::this_thread::sleep_for(std::
			chrono::milliseconds(static_cast<int>(milliseconds)));
		std::cout << "\a";
	}
}

void setColor(TextColor text, TextColor background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
		(WORD)((background << 4) | text));
}

bool wantsToPlayAgain()
{	
	const char* playAgainMsg = "Play again: 1 - "
		"yes, 0 - no: ";
	const bool playerWantsToplayAgain = 
		inputNumber(playAgainMsg, YES, NO);
	system("cls");
	return playerWantsToplayAgain;
}