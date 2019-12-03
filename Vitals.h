#ifndef VITALS_H_
#define VITALS_H_

class Vitals
{
public:
	Vitals(int value, int max_value,
		int value_regeneration = 0);
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
	void ChangeRegeneration(int regen);
	bool IsDead()const;
	void ShowFullInfo()const;
	void ShowShortInfo()const;
	operator int()const;
private:
	enum { DEAD_LINE };
	int value = 0;
	int max_value = 0;
	int value_regeneration = 0;
private:
	void FixOverflow();
};
#endif