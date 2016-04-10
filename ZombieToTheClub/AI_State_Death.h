#pragma once
#include "AI_State.h"

class Zombie;

class AI_State_Death	:	public AI_State
{
private:
	AI_State_Death();
public:
	~AI_State_Death();
	static AI_State_Death * Instance();

	virtual void Update(Zombie * _zombie);
	
	bool AniEnd(Zombie * _zombie);
};

