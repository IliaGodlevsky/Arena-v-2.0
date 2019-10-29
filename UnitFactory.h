#pragma once

#ifndef UNIT_FAC_H_
#define UNIT_FAC_H_

#include "Unit.h"

class UnitFactory
{
public:
	virtual Unit* operator()()const = 0;
};

class WarriorFactory : public UnitFactory
{
public:
	Unit* operator()()const;
};

class WizardFactory : public UnitFactory
{
public:
	Unit* operator()()const;
};

class ArcherFactory : public UnitFactory
{
public:
	Unit* operator()()const;
};

#endif