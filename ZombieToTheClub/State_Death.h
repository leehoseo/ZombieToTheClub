#pragma once
#include "State.h"
class State_Death :
	public State
{
public:
	State_Death();
	~State_Death();

	virtual void Update();
	
	bool DeathEnd();
};

