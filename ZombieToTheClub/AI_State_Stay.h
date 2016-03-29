#pragma once
#include "AI_State.h"
#include "Time.h"

class Zombie;

class AI_State_Stay :public AI_State
{
private:
	AI_State_Stay();
	Time m_time;

	bool m_rest;
public:
	static AI_State_Stay * Instance();
	~AI_State_Stay();

	virtual void Update(Zombie * _zombie);

	void SetAniDelayTime();
};

