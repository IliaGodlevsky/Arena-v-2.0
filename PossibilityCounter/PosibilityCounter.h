#ifndef POSIBILITY_H_
#define POSIBILITY_H_

class PosibilityCounter
{
public:
	explicit PosibilityCounter(int posibility);
	PosibilityCounter() = default;
	PosibilityCounter(const PosibilityCounter&) = default;
	PosibilityCounter(PosibilityCounter&&) = default;
	PosibilityCounter& operator=(const PosibilityCounter&) = default;
	PosibilityCounter& operator=(PosibilityCounter&&) = default;
	bool operator==(const PosibilityCounter& counter)const;
	int getPosibility()const;
	operator bool()const;
private:
	constexpr int getMaxPropability()const;
	int m_posibility = 0;
};

#endif