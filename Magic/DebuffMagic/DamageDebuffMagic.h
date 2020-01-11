#ifndef DAMAGE_DEBUFF_H_
#define DAMAGE_DEBUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/DamageReduceElem.h"

class DamageDebuffMagic : public ParamChangeMagic
{
public:
	DamageDebuffMagic(std::string name, int manaCost,
		Timer timer, DamageReduceElem armorReduce);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	~DamageDebuffMagic() = default;
private:
	DamageReduceElem m_damageReduce;
};

#endif