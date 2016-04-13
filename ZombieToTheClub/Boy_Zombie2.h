#pragma once
#include "Zombie.h"

class Boy_Zombie2 :public Zombie
{
public:
	Boy_Zombie2();
	virtual ~Boy_Zombie2();

	virtual void initialize();
	virtual void ChangeState(eSTATE _state);
};

