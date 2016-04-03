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
#include "AI_State_Attack.h"
#include "AI_State_Hit.h"

Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

void Zombie::initialize(float _x, float _y, Image _image, AI_State *_state)
{
	m_image = _image;
	m_attackCollisionBox = ImageManager::Instance()->AttackCollisionBox();
	m_hitCollisionBox = ImageManager::Instance()->HitCollisionBox();
	m_traceCollisionBox = ImageManager::Instance()->TraceCollsionBox();
	m_gold = ImageManager::Instance()->Gold();
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
	m_aniSpeed = 200;
	m_directionX = 0;
	m_directionY = 0;
	m_bAtk = false;
	m_time.SetStartTime();
}

void Zombie::Render()
{
	//m_attackCollisionBox.draw();
	//m_hitCollisionBox.draw();
	//m_traceCollisionBox.draw();
	m_image.draw();
}

void Zombie::Update()
{
	m_hitCollisionBox.setY(m_image.getY());

	m_traceCollisionBox.setX(m_image.getX() - 100);
	m_traceCollisionBox.setY(m_image.getY() - 100);
	
	m_attackCollisionBox.setY(m_image.getCenterY() - 40);
	
	if (Hit())
	{
		ChangeState(eSTATE::HIT);
	}

	if (Targeting())
		SetDirection(Player::Instance()->GetCenterX() - 50, Player::Instance()->GetCenterY() - 50);

	m_pstate->Update(this);
	m_image.update(200);
	IsAtk();
}

void Zombie::MoveX(float _x)
{
	if (_x < 0)
	{
		m_image.flipHorizontal(false);
		m_hitCollisionBox.setX(m_image.getX() + 50);
		m_attackCollisionBox.setX(m_image.getCenterX() - 70);
	}
	else if (_x > 0)
	{
		m_image.flipHorizontal(true);
		m_hitCollisionBox.setX(m_image.getX() + 30);
		m_attackCollisionBox.setX(m_image.getCenterX());
	}

	m_image.setX(m_image.getX() + _x);
}

void Zombie::MoveY(float _y)
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

		if (m_directionX - 10 <GetX() && GetX() < m_directionX + 10
		|| m_directionY - 10 < GetY() && GetX() < m_directionY + 10)
			m_isarrive = true;
	}
	else
	{
		SetDirection();
		++m_PatrolCount;
	}
}

void Zombie::SetDirection(int _x  , int _y )
{
	m_directionX = (rand() % 400) + (GetCenterX() - 200);
	m_directionY = (rand() % 400) * (GetCenterY() - 200);

	if( 0 > m_directionX || m_directionX > GAME_WIDTH - 128 || 
		0 > m_directionY || m_directionY > GAME_HEIGHT - 128 )
		SetDirection();

	if (_x != 0 && _y != 0)
	{
		m_directionX = _x;
		m_directionY = _y;
	}
	m_isarrive = false;
}

bool Zombie::IsDie()
{
	if (m_hp < 0)
		return true;
	else
		return false;
}

bool Zombie::Hit()
{
	if (CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetAttackCollisionBox(), this->GetHitCollisionBox()) && 
		Player::Instance()->GetCode() == eSTATE::ATTACK &&
		this->GetCode() != eSTATE::HIT )
	{
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

void Zombie::ChangeState(eSTATE _state)
{
	SetCode(_state);
	m_PatrolCount = 0;
	switch (_state)
	{
	case eSTATE::ATTACK:
		if (GetIsAtk() == false)
			return;
		ChangeImage(ImageManager::Instance()->BZ_Attack());
		m_pstate = AI_State_Attack::Instance();
		return;
	case eSTATE::HIT:
		ChangeImage(ImageManager::Instance()->BZ_Hit());
		m_pstate = AI_State_Hit::Instance();
		return;
	case eSTATE::MOVE:
		ChangeImage(ImageManager::Instance()->BZ_Move());
		m_pstate = AI_State_Move::Instance();
		return;
	case eSTATE::STAY:
		ChangeImage(ImageManager::Instance()->BZ_Stay());
		m_pstate = AI_State_Stay::Instance();
		return;
	}
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

void Zombie::SetAniSpeed(int _speed)
{
	m_aniSpeed = _speed;
}

int Zombie::GetAtk() const
{
	return m_atk;
}

void Zombie::SetHp(int _atk)
{
	m_hp += _atk;
}

Image Zombie::GetImage() const
{
	return m_image;
}

Image Zombie::GetAttackCollisionBox() const
{
	return m_attackCollisionBox;
}

Image Zombie::GetHitCollisionBox() const
{
	return m_hitCollisionBox;
}

Image Zombie::GetTraceCollsionBox() const
{
	return m_traceCollisionBox;
}

bool Zombie::IsAtk()
{
	if (m_bAtk == false)
	{
		m_time.SetTime();

		if (m_time.GetTime() > 2000)
		{
			m_bAtk = true;
			m_time.SetStartTime();
		}
	}
	return true;
}

void Zombie::SetIsAtk(bool _isAtk)
{
	m_bAtk = _isAtk;
}

bool Zombie::GetIsAtk() const
{
	return m_bAtk;
}

bool Zombie::Targeting()
{
	if (CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetImage(), GetTraceCollsionBox()))
		return true;
	else
		return false;
}

int Zombie::GetPatrolCount() const
{
	return m_PatrolCount;
}
