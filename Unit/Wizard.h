#ifndef WIZARD_H_
#define WIZARD_H_

#include "Unit.h"

#include "../Level/WizardLevel.h"

class Wizard : public Unit
{
public:
	Wizard() = delete;
	Wizard(DecisionPtr decision, Factory<Magic>* secondFactory);
	Wizard(const Wizard& unit);
	Wizard(Wizard&&);
	Wizard& operator=(const Wizard&) = delete;
	Wizard& operator=(Wizard&&) = delete;
	void payMana(int manaCost)override;
	bool isEnoughManaFor(const MagicPtr& magic)const;
	~Wizard() = default;
private:
	int countManaCost(int manaCost)const;
	void prepareMagic(MagicPtr& magic)const;
};

#endif
