#pragma once

#ifndef BATTLE_H_
#define BATTLE_H_

class BattleParam
{
	BattleParam() = default;
	BattleParam(int limit);
	BattleParam(int param, int limit);
	BattleParam operator+(int extend)const;
	int Strength()const;
	void ChangeParam(int extend);
	void ChangeLimit(int extend);
private:
	int parameter;
	int limit;
};

#endif