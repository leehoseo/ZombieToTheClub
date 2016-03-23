#include "Zombie.h"
#include <stdlib.h>
#include <time.h>


Zombie::Zombie()
{
	srand(time(NULL));
}


Zombie::~Zombie()
{
}

void Zombie::initialize(float _x, float _y, Image _image)
{
	m_image = _image;
	m_image.setX(_x);
	m_image.setY(_y);

	m_directionX = 0;
	m_directionY = 0;
	m_isarrive = false;
}

void Zombie::Render()
{
	m_image.draw();
}

void Zombie::Update()
{
	m_image.update((rand() % 10 + 5) * 100);
	SetDirection();
	Move();
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

void Zombie::Move()
{
	if (m_isarrive)
	{
		if (m_image.getX() > m_directionX)	//	목적지가 왼쪽에있다면
			m_image.setX(m_image.getX() - 1);
		else
			m_image.setX(m_image.getX() + 1);


		if (m_image.getY() > m_directionY)	//	목적지가 위쪽
			m_image.setY(m_image.getY() - 1);
		else
			m_image.setY(m_image.getY() + 1);


		if (0 > m_image.getX() || m_image.getX() > GAME_WIDTH - 128
			|| 0 > m_image.getY() || m_image.getY() > GAME_HEIGHT - 128)
			m_isarrive = false;

		if (m_image.getX() == m_directionX || m_image.getY() == m_directionY)
			m_isarrive = false;
	}
}

void Zombie::SetDirection()
{
	if (m_isarrive == false)
	{
		m_directionX = (rand() % m_image.getWidth() * 4) + (m_image.getX() - (m_image.getWidth() * 2));
		
		m_directionY = (rand() % m_image.getHeight() * 4) + (m_image.getY() - (m_image.getHeight() * 2));

		m_isarrive = true;
	}
}
