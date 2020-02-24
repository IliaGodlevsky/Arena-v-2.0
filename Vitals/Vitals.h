#ifndef VITALS_H_
#define VITALS_H_

/* A class that is responsible
for units health or mana */
class Vitals
{
	enum { DEAD_LINE, TOTAL = 100 };
public:
	Vitals(int value, int maxValue,
		int valueRegeneration = 0);
	Vitals() = default;
	Vitals(const Vitals&) = default;
	Vitals(Vitals&&) = default;
	Vitals& operator=(const Vitals&) = default;
	Vitals& operator=(Vitals&&) = default;
	Vitals operator++(int i);
	Vitals operator-(int value)const;
	Vitals operator+(const Vitals& vit)const;
	Vitals operator-(const Vitals& vit)const;
	void changeRegeneration(int regeneration);
	void restore(int percent = TOTAL);
	bool isDead()const;
	operator int()const;
	void showFullInfo(const char* vitalsType)const;
private:
	int m_value = 0;
	int m_maxValue = 0;
	int m_valueRegeneration = 0;
	void fixOverflow();
	void setValueColor()const;
	void setRegenColor()const;
	bool isHighHpLevel()const;
	bool isNormalHpLevel()const;
};
#endif