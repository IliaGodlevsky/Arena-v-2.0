#ifndef FREE_PARAM_CHANGE_MAGIC_H_
#define FREE_PARAM_CHANGE_MAGIC_H_

#include "Magic.h"
#include "../Interface/Interface.h"
#include "Elements/ParamChangeElem.h"
#include "../Expiring/Expiring.h"

/* A base for all magic, that can be casted by weapon*/
class FreeParamChangeMagic : public Magic, 
	public IUneffect, public IDispelable, public Expiring
{
public:
	FreeParamChangeMagic(std::string name, Time time);
	virtual void effectUnit(Unit& unit) = 0;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
	virtual ~FreeParamChangeMagic() = default;
};
#endif
