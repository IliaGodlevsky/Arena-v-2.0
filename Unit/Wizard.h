#ifndef WIZARD_H_
#define WIZARD_H_

#include "Unit.h"

#include "../Level/WizardLevel.h"

class Wizard : public Unit
{
public:
	Wizard(DecisionPtr decision, ItemFactoryPtr factory, 
		Factory<Magic>* secondFactory);
	Wizard(const Wizard& unit);
	void payMana(int manaCost)override;
	bool castMagic(Unit& unit, MagicPtr& magic);
	bool isEnoughManaFor(const MagicPtr& magic)const;
	~Wizard() = default;
private:
	int countManaCost(int manaCost)const;
};

#endif
