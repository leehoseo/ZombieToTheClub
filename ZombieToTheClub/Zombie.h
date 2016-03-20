#pragma once

#include "image.h"
#include "Resource.h"
#include "graphics.h"

class Zombie
{
private:
	Image m_image;

public:
	Zombie();
	~Zombie();

	void initialize(int _x = 0 , int _y = 0);
	void Render();
	void Update();

	void SetX(int _x);
	void SetY(int _y);
	int GetX() const;
	int GetY() const;
};

