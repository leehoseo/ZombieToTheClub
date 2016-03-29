#pragma once

#include "image.h"
#include "Resource.h"
#include "graphics.h"
#include "Zombie.h"

class Boy_Zombie	:	public Zombie
{
private:
	
public:
	Boy_Zombie();
	~Boy_Zombie();

	virtual void initialize(float _x, float _y, Image _image, AI_State *_state);

};

