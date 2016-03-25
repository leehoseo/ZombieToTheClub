#pragma once
#include "AI_State.h"
#include "Zombie.h"

class AI_State_Move	: public AI_State
{
public:
	AI_State_Move();
	~AI_State_Move();

	virtual void Update(Zombie * _zombie);
};

