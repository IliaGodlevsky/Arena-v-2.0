#pragma once

#ifndef POSIBILITY_H_
#define POSIBILITY_H_

class PosibilityCounter
{
public:
	PosibilityCounter(int posibility);
	operator bool()const;
private:
	int getMaxPropability()const;
	int m_posibility;
};
#endif