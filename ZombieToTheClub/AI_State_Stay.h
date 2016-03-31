#pragma once
#include "AI_State.h"
#include "Time.h"

class Zombie;

class AI_State_Stay :public AI_State
{
private:
	AI_State_Stay();
	Time m_time;
public:
	static AI_State_Stay * Instance();
	~AI_State_Stay();

	virtual void Update(Zombie * _zombie);
	bool StayCheck(Zombie * _zombie);
};

