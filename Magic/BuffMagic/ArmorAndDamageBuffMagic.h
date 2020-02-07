#ifndef ARMOR_AND_DAMAGE_BUFF_H_
#define ARMOR_AND_DAMAGE_BUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/ArmorAmplifyElem.h"
#include "../Elements/DamageAmplifyElem.h"

class ArmorAndDamageBuffMagic
	: public ParamChangeMagic
{
public:
	ArmorAndDamageBuffMagic(std::string name, int manaCost,
		Time time, ArmorAmplifyElem armorAmplify, 
		DamageAmplifyElem damageAmplify);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	~ArmorAndDamageBuffMagic() = default;
private:
	ArmorAmplifyElem m_armorAmplify;
	DamageAmplifyElem m_damageAmplify;
};

#endif