#pragma once

#include "State.h"

class State_Attack3 : public State
{

public:
	State_Attack3();
	~State_Attack3();

	virtual void Update();

	bool AttackEnd();
};

