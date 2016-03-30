#pragma once
#include "AI_State.h"

class Zombie;

class AI_State_Attack	:	public AI_State
{
public:
	AI_State_Attack();
	~AI_State_Attack();

	virtual void Update(Zombie * _zombie);
};

