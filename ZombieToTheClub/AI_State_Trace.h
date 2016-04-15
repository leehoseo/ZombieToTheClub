#pragma once
#include "AI_State.h"


class AI_State_Trace :	public AI_State
{
private:
	AI_State_Trace();
public:
	~AI_State_Trace();

	static AI_State_Trace * Instance();

	virtual void Update(Zombie * _zombie);
};

