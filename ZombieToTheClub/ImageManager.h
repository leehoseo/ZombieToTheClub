#pragma once
#include "graphics.h"
#include "image.h"

class ImageManager
{
private:
	Image m_pzombie_1;
	ImageManager();

public:
	static ImageManager* Instance();

	virtual void initialize(Graphics* g);
	
	virtual ~ImageManager();

	Image Zombie_1();
};

