#pragma once
#include "Zombie.h"

class Main_Zombie	:	public Zombie
{
public:
	Main_Zombie();
	~Main_Zombie();

	virtual void initialize(float _x, float _y, Image _image, AI_State *_state);

	virtual void Move();

	virtual void SetDirection();

	virtual void Update();
	virtual void Render();
};

