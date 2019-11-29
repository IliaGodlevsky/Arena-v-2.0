#include "Battles.h"

Battles::Battles(int value)
	: value(value)
{

}

void Battles::ChangeValue(int value)
{
	this->value = value;
}

Battles::operator int()const
{
	return value;
}