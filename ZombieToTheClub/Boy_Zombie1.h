#pragma once

#include "image.h"
#include "Resource.h"
#include "graphics.h"
#include "Zombie.h"

class Boy_Zombie1	:	public Zombie
{
private:
	
public:
	Boy_Zombie1();
	~Boy_Zombie1();

	virtual void initialize();
	virtual void ChangeState(eSTATE _state);
};

