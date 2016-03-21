#pragma once

#include "image.h"
#include "Resource.h"
#include "graphics.h"

class Zombie
{
private:
	Image m_image;
	bool m_bMove;



public:
	Zombie();
	~Zombie();

	void initialize(float _x = 0 , float _y = 0);
	void Render();
	void Update();

	void SetX(int _x);
	void SetY(int _y);
	int GetX();
	int GetY();

	void Patrol();
};
