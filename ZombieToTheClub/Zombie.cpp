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

	/*if (!m_image_Zombi.initialize(this->m_pgraphics, 0, 0, 0, Zombi1_IMAGE))
	{
		PostQuitMessage(0);
	}*/
}

Image* Zombie::GetImage()
{
	return &m_image_Zombi;
}