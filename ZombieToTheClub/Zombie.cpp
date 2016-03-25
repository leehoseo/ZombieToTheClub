#include "Zombie.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Player.h"
#include "AI_State_Move.h"
Zombie::Zombie()
{
	srand(time(NULL));
}


Zombie::~Zombie()
{
	SAFE_DELETE(m_pstate);
}

void Zombie::initialize(float _x, float _y, Image _image)
{
	m_image = _image;
	m_image.setX(_x);
	m_image.setY(_y);

	m_pstate = new AI_State_Move();

	m_directionX = 0;
	m_directionY = 0;
	m_isarrive = false;

	m_hp = 35;
	m_atk = 8;
	m_moveSpeed = 0.5;
	atdSpeed = 2;
	m_experience = 5;
	m_score = 1;
}

void Zombie::Render()
{
	m_image.draw();
}

void Zombie::Update()
{
	m_image.update((rand() % 10 + 5) * 100);
	m_pstate->Update(this);
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
			m_image.setX(m_image.getX() - 1 * m_moveSpeed);
		else
			m_image.setX(m_image.getX() + 1 * m_moveSpeed);


		if (m_image.getY() > m_directionY)	//	목적지가 위쪽
			m_image.setY(m_image.getY() - 1 * m_moveSpeed);
		else
			m_image.setY(m_image.getY() + 1 * m_moveSpeed);


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

bool Zombie::Hit()
{
	/*if(m_image.getSpriteDataRect().)
	return false;*/
	return true;
}
