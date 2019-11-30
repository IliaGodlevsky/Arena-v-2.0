#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <string>
#include <vector>

class Unit;
using UnitPtr = std::shared_ptr<Unit>;
using Gladiators = std::vector<UnitPtr>;
class Decision;

class Magic;
using MagicPtr = std::unique_ptr<Magic>;
using Spells = std::vector<MagicPtr>;

int input(const std::string& message, int upper, int lower);
bool error(int choice, int upper, int lower);
void eatline();

inline int randomIndex(int arraySize);

#endif
