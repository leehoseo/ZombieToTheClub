#include "Zombie.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Player.h"
#include "CrashCheck.h"
#include <stdio.h>
#include "ImageManager.h"
#include "Resource.h"
#include "AI_State_Move.h"
#include "AI_State_Stay.h"

Zombie::Zombie()
{
	srand(time(NULL));
}


Zombie::~Zombie()
{
}

void Zombie::initialize(float _x, float _y, Image _image, AI_State *_state)
{
	m_image = _image;
	m_test = ImageManager::Instance()->Test();

	m_image.setX(_x);
	m_image.setY(_y);

	m_hp = 35;
	m_atk = 8;
	m_moveSpeed = 0.5;
	atdSpeed = 2;
	m_experience = 5;
	m_score = 1;
	m_type = eTYPE::BZ;
	m_pstate = _state;
}

void Zombie::Render()
{
	m_image.draw();
	m_test.draw();
}

void Zombie::Update()
{
	/*m_test.setX(m_image.getCenterX() - 20);
	m_test.setY(m_image.getCenterY());
	Hit();*/
	printf("HP : %d\n", m_hp);
	m_image.update((rand() % 10 + 5) * 100);
	m_pstate->Update(this);	
}

void Zombie::SetX(float _x)
{
	if (_x < 0)
		m_image.flipHorizontal(false);
	else if (_x > 0)
		m_image.flipHorizontal(true);

	m_image.setX(m_image.getX() + _x);
}

void Zombie::SetY(float _y)
{
	m_image.setY(m_image.getY() + _y);
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
	//if (m_isarrive)
	//{
	//	if (m_image.getX() > m_directionX)	//	목적지가 왼쪽에있다면
	//		SetX(- 1 * m_moveSpeed);
	//	else
	//		SetX(1 * m_moveSpeed);


	//	if (m_image.getY() > m_directionY)	//	목적지가 위쪽
	//		SetY(- 1 * m_moveSpeed);
	//	else
	//		SetY(+ 1 * m_moveSpeed);


	//	if (0 > m_image.getX() || m_image.getX() > GAME_WIDTH - 128
	//		|| 0 > m_image.getY() || m_image.getY() > GAME_HEIGHT - 128)
	//		m_isarrive = false;

	//	if (m_image.getX() == m_directionX || m_image.getY() == m_directionY)
	//		m_isarrive = false;
	//}
	//else
	//{
	//	SetDirection();
	//}
}

void Zombie::SetDirection()
{
	/*m_directionX = (rand() % m_image.getWidth() * 4) + (m_image.getX() - (m_image.getWidth() * 2));

	m_directionY = (rand() % m_image.getHeight() * 4) + (m_image.getY() - (m_image.getHeight() * 2));

	m_isarrive = true;*/
}

bool Zombie::Hit()
{
	double x = Player::Instance()->GetCenterX() - this->GetCenterX();
	double y = Player::Instance()->GetCenterY() - this->GetCenterY();

	//printf("%d \n", m_hp);
	if(CrashCheck::Instance()->Circle_Circle(50 , 50 , _hypot(fabs(x) , fabs(y))) && Player::Instance()->GetCode() == eSTATE::ATTACK)
	{
		m_hp -= Player::Instance()->GetAtk();
		return true;
	}
	else
		return false;
}

float Zombie::GetRadius() const
{
	return m_image.getRadius();
}

float Zombie::GetCenterX() const
{
	return m_image.getCenterX();
}

float Zombie::GetCenterY() const
{
	return m_image.getCenterY();
}

int Zombie::GetCode() const
{
	return m_code;
}

void Zombie::SetCode(eSTATE _code)
{
	m_code = _code;
}

void Zombie::ChangeState(AI_State * _newState)
{
	m_pstate = _newState;
}

void Zombie::ChangeImage(Image _image)
{
	int tempX = m_image.getX();
	int tempY = m_image.getY();
	bool tempH = m_image.GetHorizontal();

	m_image = _image;

	m_image.setX(tempX);
	m_image.setY(tempY);
	m_image.flipHorizontal(tempH);
}

int Zombie::GetCurrentFrame() const
{
	return m_image.GetCurrentFrame();
}

int Zombie::GetFrame() const
{
	return m_image.GetFrame();
}

int Zombie::GetType() const
{
	return m_type;
}

Image Zombie::GetImage() const
{
	return m_image;
}
