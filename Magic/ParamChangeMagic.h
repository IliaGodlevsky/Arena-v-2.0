#ifndef PARAM_CHANGE_MAGIC_H_
#define PARAM_CHANGE_MAGIC_H_

#include "FreeParamChangeMagic.h"
#include "../Interface/Interface.h"
#include "Elements/ParamChangeElem.h"

/* A base class for all magic, that comes to magic book*/
class ParamChangeMagic : public FreeParamChangeMagic, 
	public IBuff, public IManaCost
{
public:
	ParamChangeMagic(std::string name, int manaCost,
		Time time);
	virtual void effectUnit(Unit& unit) = 0;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
	virtual ~ParamChangeMagic() = default;
};
#endif
