#include "Main_Zombie.h"
#include "ImageManager.h"


Main_Zombie::Main_Zombie()
{
}


Main_Zombie::~Main_Zombie()
{
}

void Main_Zombie::initialize(float _x, float _y, Image _image, AI_State * _state)
{
	m_image = _image;
	m_image.setX(_x);
	m_image.setY(_y);

	m_directionX = rand() % (GAME_WIDTH - 148) + 10;
	m_directionY = rand() % 300 + 470;

	m_hp = 35;
	m_atk = 8;
	m_moveSpeed = 0.5;
	atdSpeed = 2;
	m_experience = 5;
	m_score = 1;
	m_type = eTYPE::BZ;
	m_pstate = _state;
	m_aniSpeed = 200;
}

void Main_Zombie::Move()
{
	if (m_isarrive == false)
	{
		if (GetX() > m_directionX)	//	목적지가 왼쪽에있다면
			MoveX(-2);
		else
			MoveX(2);

		if (GetY() > m_directionY)	//	목적지가 위쪽
			MoveY(-2);
		else
			MoveY(2);

		if (m_directionX - 5 < GetX() && GetX() < m_directionX + 5
			|| m_directionY - 5 < GetY() && GetX() < m_directionY + 5)
		{
			m_isarrive = true;
		}
	}
	else
	{
		SetDirection();
	}
}

void Main_Zombie::SetDirection()
{
	m_directionX = rand() % (GAME_WIDTH - 148) + 10;
	m_directionY = rand() % 350 + 420;

	m_isarrive = false;
	++m_PatrolCount;
}

void Main_Zombie::Update()
{
	m_image.update(m_aniSpeed);
	Move();
}

void Main_Zombie::Render()
{
	m_image.draw();
}
