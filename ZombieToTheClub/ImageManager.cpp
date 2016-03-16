#include "ImageManager.h"
#include "Resource.h"


ImageManager::ImageManager()
{

}


ImageManager::~ImageManager()
{
}

ImageManager* ImageManager::Instance()
{
	static ImageManager instance;

	return &instance;
}


void ImageManager::initialize(Graphics * g)
{
	m_pzombie_1.initialize(g, 0, 0, 0, "Resource\\Zombie1.png");
}

Image ImageManager::Zombie_1()
{
	return m_pzombie_1;
}
