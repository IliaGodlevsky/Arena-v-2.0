#ifndef VITALS_H_
#define VITALS_H_

class Vitals
{
public:
	Vitals(int value, int maxValue,
		int valueRegeneration = 0);
	Vitals() = default;
	Vitals(const Vitals&) = default;
	Vitals(Vitals&&) = default;
	Vitals& operator=(const Vitals&) = default;
	Vitals& operator=(Vitals&&) = default;
public:
	Vitals operator++(int i);
	Vitals operator-(int value)const;
	Vitals operator+(const Vitals& vit)const;
	Vitals operator-(const Vitals& vit)const;
	void changeRegeneration(int regeneration);
	void restore(int percent);
	bool isDead()const;
	operator int()const;
	void showFullInfo(const char* vitalsType)const;
private:
	enum { DEAD_LINE };
	int m_value = 0;
	int m_maxValue = 0;
	int m_valueRegeneration = 0;
private:
	void fixOverflow();
};
#endif