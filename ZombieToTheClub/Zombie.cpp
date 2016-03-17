#include "Zombie.h"
#include "ImageManager.h"


Zombie::Zombie()
{

}


Zombie::~Zombie()
{
}

void Zombie::initialize()
{
	m_image_Zombi = ImageManager::Instance()->Zombie_1();
}

Image* Zombie::GetImage()
{
	return &m_image_Zombi;
}