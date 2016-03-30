#pragma once
#include "AI_State.h"

class Zombie;

class AI_State_Attack	:	public AI_State
{
private:
	AI_State_Attack();
public:
	~AI_State_Attack();
	static AI_State_Attack * Instance();

	virtual void Update(Zombie * _zombie);
	
	void Attack(Zombie * _zombie);
	bool AttackCheck(Zombie * _zombie);

};

