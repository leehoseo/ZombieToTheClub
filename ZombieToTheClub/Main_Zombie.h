#pragma once
#include "Zombie.h"

class Main_Zombie	:	public Zombie
{
public:
	Main_Zombie();
	~Main_Zombie();

	virtual void initialize();

	virtual void Move();

	virtual void SetDirection();

	virtual void Update();
	virtual void Render();
	virtual void ChangeState(eSTATE _state);
};

