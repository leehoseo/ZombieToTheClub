#include "ImageManager_Play.h"



ImageManager_Play::ImageManager_Play()
{
}

ImageManager_Play * ImageManager_Play::Instance()
{
	static ImageManager_Play instance;
	return nullptr;
}


void ImageManager_Play::initialize(Graphics * g)
{
	m_pzombie_1->initialize(g, 0, 0, 0, "Resource\\Zombie1.png");
}

ImageManager_Play::~ImageManager_Play()
{
	SAFE_DELETE(m_pzombie_1);
}

Image ImageManager_Play::Zombie_1()
{
	return *m_pzombie_1;
}
