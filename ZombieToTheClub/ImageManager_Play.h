#pragma once
#include "ImageManager.h"
#include "image.h"

class ImageManager_Play	: public ImageManager
{
private:
	Image* m_pzombie_1;

	ImageManager_Play();

public:
	static ImageManager_Play* Instance();

	virtual void initialize(Graphics* g);
	virtual ~ImageManager_Play();

	Image Zombie_1();
};

