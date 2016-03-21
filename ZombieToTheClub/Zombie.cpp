#include "Zombie.h"
#include "ImageManager.h"
#include <time.h>
#include <stdlib.h>

Zombie::Zombie()
{
	srand(time(NULL));
}


Zombie::~Zombie()
{
}

void Zombie::initialize(float _x , float _y)
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

int Zombie::GetX()
{
	return m_image.getX();
}

int Zombie::GetY()
{
	return m_image.getY();
}

void Zombie::Patrol()
{
}
