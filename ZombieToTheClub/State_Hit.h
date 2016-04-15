#pragma once
#include "State.h"
class State_Hit	:	public State
{
public:
	State_Hit();
	~State_Hit();

	virtual void Update();
	bool HitEnd();
};

