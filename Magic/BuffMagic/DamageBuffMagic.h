#ifndef DAMAGE_BUFF_H_
#define DAMAGE_BUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/DamageAmplifyElem.h"

class DamageBuffMagic : public ParamChangeMagic
{
public:
	DamageBuffMagic(std::string name, int manaCost,
		Time time, DamageAmplifyElem armorAmplify);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	~DamageBuffMagic() = default;
private:
	DamageAmplifyElem m_damageAmplify;
};

#endif