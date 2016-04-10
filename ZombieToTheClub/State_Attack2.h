#pragma once
#include "State.h"

class State_Attack2 : public State
{

public:
	State_Attack2();
	~State_Attack2();

	virtual void Update();

	bool AttackEnd();
};

