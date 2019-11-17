#pragma once

#ifndef BATTLES_H_
#define BATTLES_H_

class Battles
{
public:
	explicit Battles(int value);
	virtual void ChangeValue(int value) final;
	virtual int Value()const final;
protected:
	int value;
};
#endif