#pragma once
#include "Zombie.h"
class Boy_Zombie3 :
	public Zombie
{
public:
	Boy_Zombie3();
	virtual ~Boy_Zombie3();

	virtual void initialize();
	virtual void ChangeState(eSTATE _state);
};

