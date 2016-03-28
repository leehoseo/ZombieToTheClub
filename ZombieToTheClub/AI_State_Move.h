
#pragma once
#include "AI_State.h"

class Zombie;

class AI_State_Move : public AI_State
{
private:
	AI_State_Move();

	int m_PatrolCount;

	int m_directionX;
	int m_directionY;

	bool m_isarrive;
public:
	
	static AI_State_Move * Instance();
	~AI_State_Move();

	virtual void Update(Zombie * _zombie);

	void SetDirection(Zombie * _zombie);

	void Move(Zombie * _zombie);
};