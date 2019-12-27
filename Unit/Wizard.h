#ifndef WIZARD_H_
#define WIZARD_H_

#include "Unit.h"

#include "../Level/WizardLevel.h"

class Wizard : public Unit
{
public:
	Wizard(std::string name, DecisionPtr decision,
		ItemFactoryPtr factory, Factory<Magic>* secondFactory);
	Wizard(const Wizard& unit);
	void payMana(int manaCost)override;
};

#endif
