#pragma once

#ifndef POSIBILITY_H_
#define POSIBILITY_H_

class PosibilityCounter
{
public:
	PosibilityCounter(int posibility);
	bool IsChance()const;
private:
	static const int MAX_PROPABILITY = 100;
	int posibility;
};
#endif