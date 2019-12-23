#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

#include "../Messager/Messager.h"

class Unit;
using UnitPtr = std::shared_ptr<Unit>;
using Gladiators = std::vector<UnitPtr>;

class Decision;

class Magic;
using MagicPtr = std::unique_ptr<Magic>;
using Spells = std::vector<MagicPtr>;

typedef unsigned index;

constexpr int ZERO_DURATION = 0;
constexpr int ZERO_MANA_COST = 0;
constexpr int ZERO_CRITIAL_PROBABILITY = 0;

int inputNumber(const std::string& message, int upper, int lower);
bool isError(int choice, int upper, int lower);
void eatLine();

int randomNumber(int max, int min = 0);
std::vector<std::string> loadFromFile(const std::string& fileName);

#endif
