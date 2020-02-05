#ifndef FREE_PARAM_CHANGE_MAGIC_H_
#define FREE_PARAM_CHANGE_MAGIC_H_

#include "Magic.h"
#include "../Interface/Interface.h"
#include "Elements/ParamChangeElem.h"
#include "../Timer/Timer.h"

/* A base for all magic, that can be casted by weapon*/
class FreeParamChangeMagic : public Magic, 
	public IUneffect, public IDispelable, public IDuration
{
public:
	FreeParamChangeMagic(std::string name, Timer timer);
	virtual void effectUnit(Unit& unit) = 0;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
	int getDuration()const override;
	int getStartTime()const override;
	void setStartTime(int round)override;
	bool isExpired()const override;
	virtual ~FreeParamChangeMagic() = default;
};
#endif
