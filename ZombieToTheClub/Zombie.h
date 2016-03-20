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

	void initialize();
	Image* GetImage();
};

