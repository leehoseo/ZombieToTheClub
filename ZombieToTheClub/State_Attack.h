#pragma once
#include "State.h"
#include "Time.h"

class State_Attack : public State
{
private:
	Time m_time;
public:
	State_Attack();
	~State_Attack();

	virtual void Update();

	bool AttackEnd();
};
