#pragma once
#include "State.h"
#include "image.h"
class State_Stay : public State
{
public:
	~State_Stay();
	State_Stay();
	virtual void Render();
	virtual void Update();

	bool MoveCheck();
};

