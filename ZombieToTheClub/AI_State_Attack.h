#pragma once
#include "AI_State.h"

class Zombie;

class AI_State_Attack	:	public AI_State
{
private:
	AI_State_Attack();
public:
	~AI_State_Attack();
	static AI_State_Attack * Instance();

	virtual void Update(Zombie * _zombie);
	
	bool AniEnd(Zombie * _zombie);
};

