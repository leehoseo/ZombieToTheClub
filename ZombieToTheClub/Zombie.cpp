#include "Zombie.h"
#include "ImageManager.h"


Zombie::Zombie()
{

}


Zombie::~Zombie()
{
}

void Zombie::initialize(int _x , int _y)
{
	m_image = ImageManager::Instance()->Zombie_1();
	m_image.setX(_x);
	m_image.setY(_y);
}

void Zombie::Render()
{
	m_image.draw();
}

void Zombie::Update()
{
}

void Zombie::SetX(int _x)
{
	m_image.setX(_x);
}

void Zombie::SetY(int _y)
{
	m_image.setY(_y);
}

int Zombie::GetX() const
{
	return m_image.getX();
}

int Zombie::GetY() const
{
	return m_image.getY();
}
