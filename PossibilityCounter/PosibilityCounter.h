#ifndef POSIBILITY_H_
#define POSIBILITY_H_

class PosibilityCounter
{
public:
	explicit PosibilityCounter(int posibility);
	operator bool()const;
private:
	constexpr int getMaxPropability()const;
	int m_posibility;
};

#endif