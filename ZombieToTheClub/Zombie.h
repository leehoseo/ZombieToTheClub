#pragma once

#include "image.h"
#include "Resource.h"
#include "graphics.h"

class Zombie
{
private:
	Image m_image_Zombi;

public:
	Zombie();
	~Zombie();

	void initialize();
	Image* GetImage();
};

