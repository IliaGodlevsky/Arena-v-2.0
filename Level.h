#pragma once

#ifndef LEVEL_H_
#define LEVEL_H_

class Level
{
public:
	Level() = default;
	Level(int level, long long experience);
	Level operator++(int i);
	Level operator+(long long experience)const;
	Level operator+=(long long experience)const;
	long long NextLevelRequire()const;
private:
	int level;
	long long experience;
};

#endif