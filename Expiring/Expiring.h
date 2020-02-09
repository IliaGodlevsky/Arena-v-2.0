#ifndef EXPIRING_H_
#define EXPIRING_H_

#include "../Interface/Interface.h"

struct Time 
{ 
	Time(int duration, int startTime = 0);
	Time(const Time&) = default;
	int duration = 0;
	int startTime = 0;
};

class Expiring : public IExpirable
{
public:
	Expiring(int duration, int startTime = 0);
	Expiring(Time time);
	Expiring() = default;
	Expiring(const Expiring&) = default;
	Expiring(Expiring&&) = default;
	Expiring& operator= (const Expiring&) = default;
	Expiring& operator= (Expiring&&) = default;
	virtual ~Expiring() = 0;
	bool isExpired()const override;
	void setStartTime(int round);
	bool operator==(const Expiring& expiring)const;
	int getDuration()const;
	int getStartTime()const;
	int getDurationRemained()const;
	void makeExpire();
protected:
	Time m_time;
};
#endif