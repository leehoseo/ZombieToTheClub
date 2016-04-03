#pragma once
#include "AI_State.h"
#include "Time.h"

class Zombie;

class AI_State_Move : public AI_State
{
private:
	AI_State_Move();

public:
	
	static AI_State_Move * Instance();
	~AI_State_Move();

	virtual void Update(Zombie * _zombie);
};
