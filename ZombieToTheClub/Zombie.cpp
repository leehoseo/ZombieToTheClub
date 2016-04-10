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
#include "AI_State_Death.h"

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

	m_directionX = rand() % (GAME_WIDTH - 148) + 10;
	m_directionY = rand() % 590;

	m_image.setX(_x);
	m_image.setY(_y);

	m_hp = 35;
	m_atk = 8;
	m_moveSpeed = 0.5;
	atdSpeed = 2;
	m_experience = 5;
	m_score = 100;
	m_type = eTYPE::BZ;
	m_pstate = _state;
	m_aniSpeed = 200;
	m_directionX = 0;
	m_directionY = 0;
	m_batk = false;
	m_isarrive = true;
	m_bdeath = false;
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

	m_traceCollisionBox.setX(m_image.getX() - 50);
	m_traceCollisionBox.setY(m_image.getY() - 50);
	
	m_attackCollisionBox.setY(m_image.getCenterY() - 40);
	
	if ( this->Hit() == true )
	{
		ChangeState(eSTATE::HIT);
	}

	if (this->m_hp < 0	&& this->GetCode() != eSTATE::DEATH)
	{
		ChangeState(eSTATE::DEATH);
	}

	m_pstate->Update(this);
	m_image.update(m_aniSpeed);
	Attackable();
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

void Zombie::Move()
{
	if (this->Targeting() == true)
	{
		this->SetDirection(Player::Instance()->GetX() + 40, Player::Instance()->GetY() + 40);
	}

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

void Zombie::SetDirection(int _x, int _y)
{
	m_directionX = rand() % (GAME_WIDTH - 148) + 10;
	m_directionY = rand() % 590;

	if (_x != 0 && _y != 0)
	{
		m_directionX = _x;
		m_directionY = _y;
	}

	m_isarrive = false;
	++m_PatrolCount;
}

bool Zombie::IsDie()
{
	if (m_hp < 0)
	{
		return true;
	}
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

bool Zombie::Attack()
{
	if (CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetHitCollisionBox(), this->GetAttackCollisionBox()) && this->GetCode() != eSTATE::ATTACK)
		return true;
	else
		return false;
}

void Zombie::SetCoordinate(int _x, int _y)
{
	m_image.setX(_x);
	m_image.setY(_y);
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
		ChangeImage(ImageManager::Instance()->BZ1_Attack());
		m_pstate = AI_State_Attack::Instance();
		return;
	case eSTATE::HIT:
		ChangeImage(ImageManager::Instance()->BZ1_Hit());
		m_pstate = AI_State_Hit::Instance();
		return;
	case eSTATE::MOVE:
		ChangeImage(ImageManager::Instance()->BZ1_Move());
		m_pstate = AI_State_Move::Instance();
		return;
	case eSTATE::STAY:
		ChangeImage(ImageManager::Instance()->BZ1_Stay());
		m_pstate = AI_State_Stay::Instance();
		return;
	case eSTATE::DEATH:
		ChangeImage(ImageManager::Instance()->BZ1_Death());
		m_pstate = AI_State_Death::Instance();
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

bool Zombie::Targeting()
{
	if (CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetHitCollisionBox(), this->GetTraceCollsionBox()))
	{
		return true;
	}
	else
		return false;
}


void Zombie::SetAniSpeed(int _speed)
{
	m_aniSpeed = _speed;
}

void Zombie::SetHp(int _atk)
{
	m_hp += _atk;
}

bool Zombie::Attackable()
{
	if (m_batk == false)
	{
		m_time.SetTime();

		if (m_time.GetTime() > 2000)
		{
			m_batk = true;
			m_time.SetStartTime();
		}
	}
	return true;
}

void Zombie::SetIsAtk(bool _isAtk)
{
	m_batk = _isAtk;
}

void Zombie::SetDeath(bool _death)
{
	m_bdeath = _death;
}


void Zombie::SetCode(eSTATE _code)
{
	m_code = _code;
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


int Zombie::GetAtk() const
{
	return m_atk;
}

bool Zombie::GetIsAtk() const
{
	return m_batk;
}

int Zombie::GetPatrolCount() const
{
	return m_PatrolCount;
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

int Zombie::GetCode() const
{
	return m_code;
}

int Zombie::GetScore() const
{
	return m_score;
}

bool Zombie::GetDeath() const
{
	return m_bdeath;
}

int Zombie::GetX() const
{
	return m_image.getX();
}

int Zombie::GetY() const
{
	return m_image.getY();
}