#pragma once
#include "State.h"


class State_Move	: public State
{
public:
	State_Move();
	~State_Move();

	virtual void Update();

	void Move();
	bool MoveCheck();
	
};

