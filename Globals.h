#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <string>
#include <vector>

class Unit;
using UnitPtr = std::shared_ptr<Unit>;

class Magic;
using MagicPtr = std::unique_ptr<Magic>;

#endif
