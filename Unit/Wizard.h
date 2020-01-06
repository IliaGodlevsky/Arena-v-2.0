#ifndef WIZARD_H_
#define WIZARD_H_

#include "Unit.h"

#include "../Level/WizardLevel.h"

class Wizard : public Unit
{
public:
	Wizard() = delete;
	Wizard(DecisionPtr decision, ItemFactoryPtr factory, 
		Factory<Magic>* secondFactory);
	Wizard(const Wizard& unit);
	Wizard(Wizard&&);
	Wizard& operator=(const Wizard&) = delete;
	Wizard& operator=(Wizard&&) = delete;
public:
	void payMana(int manaCost)override;
	bool castMagic(Unit& unit, MagicPtr& magic);
	bool isEnoughManaFor(const MagicPtr& magic)const;
	UnitPtr getPureClone()const override;
	~Wizard() = default;
private:
	int countManaCost(int manaCost)const;
};

#endif
