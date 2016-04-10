#pragma once
#include "AI_State.h"
#include "Time.h"

class Zombie;

class AI_State_Hit	:	public AI_State
{
private:
	AI_State_Hit();
public:
	
	static AI_State_Hit * Instance();

	~AI_State_Hit();

	virtual void Update(Zombie * _zombie);

	bool AniEnd(Zombie * _zombie);
};

