#pragma once
#include "State.h"
#include "Time.h"

class State_Attack : public State
{
public:
	State_Attack();
	~State_Attack();

	virtual void Update();

	bool AttackEnd();
};
