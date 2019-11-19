#include "Battles.h"

Battles::Battles(int value)
	: value(value)
{

}

void Battles::ChangeValue(int value)
{
	this->value = value;
}

int Battles::Value()const
{
	return value;
}