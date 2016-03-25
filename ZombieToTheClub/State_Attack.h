#pragma once
#include "State.h"

class State_Attack	: public State
{
public:
	State_Attack();
	~State_Attack();

	virtual void Update();

	void Attack();
	bool AttackCheck();
};

