#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <windows.h>

#include "../Messager/Messager.h"
#include "../Exceptions/EmptyContainerException.h"
#include "../Exceptions/BadWeaponMagicException.h"
#include "../Exceptions/BadEquipmentException.h"
#include "../Exceptions/BadincomingMagicException.h"
#include "../Exceptions/ArenaUninterseptedException.h"

#define YES true
#define NO !YES
#define NULLPTR nullptr

enum TextColor {
	BLACK, BLUE, GREEN, CYAN, RED, MAGNETA,
	BROWN, LIGHT_GREY, DARK_GREY, LIGHT_BLUE,
	LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED,
	LIGHT_MAGNETA, YELLOW, WHITE
};

void setColor(TextColor text = WHITE, TextColor background = BLACK);

class Unit;
using UnitPtr = std::shared_ptr<Unit>;
using Gladiators = std::vector<UnitPtr>;

class Decision;
using DecisionPtr = std::shared_ptr<Decision>;

class Magic;
using MagicPtr = std::unique_ptr<Magic>;

typedef unsigned index;

int inputNumber(const std::string& message, int upper, int lower);
bool isError(int choice, int upper, int lower);
void eatLine();

int randomNumber(int max, int min = 0);
std::vector<std::string> loadFromFile(const std::string& fileName);

void exceptionMessage(std::exception& ex);
void myTerminate();

const char* const teamPlayQuest = "Do you want to play "
"in teams? <1 - yes, 0 - no>: ";

#endif
