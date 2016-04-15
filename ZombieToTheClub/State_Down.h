#pragma once
#include "State.h"
class State_Down : public State
{
public:
	State_Down();
	virtual ~State_Down();

	virtual void Update();

	bool DownEnd();
};

