#include "Main_Zombie.h"
#include "AI_State_Move.h"
#include "AI_State_Stay.h"
#include "AI_State_Attack.h"
#include "AI_State_Hit.h"
#include "AI_State_Death.h"
#include "ImageManager.h"


Main_Zombie::Main_Zombie()
{
}


Main_Zombie::~Main_Zombie()
{
}

void Main_Zombie::initialize()
{
	if (rand() % 2)
	{
		ChangeState(eSTATE::STAY);
	}
	else
	{
		ChangeState(eSTATE::MOVE);
	}

	m_image.setX(rand() % (GAME_WIDTH - 148) + 10);
	m_image.setY(rand() % 242 + 520);

	m_directionX = rand() % (GAME_WIDTH - 148) + 10;
	m_directionY = rand() % 242 + 520;

	m_hp = 35;
	m_atk = 8;
	m_moveSpeed = 0.5;
	atdSpeed = 2;
	m_experience = 5;
	m_score = 1;
	m_type = eTYPE::BZ;
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
	m_directionY = rand() % 242 + 520;

	m_isarrive = false;
	++m_PatrolCount;
}

void Main_Zombie::Update()
{
	m_image.update(m_aniSpeed);
	//Move();
	m_pstate->Update(this);
}

void Main_Zombie::Render()
{
	m_image.draw();
}

void Main_Zombie::ChangeState(eSTATE _state)
{
	SetCode(_state);

	m_PatrolCount = 0;
	switch (_state)
	{
	case eSTATE::ATTACK1:
		if (GetIsAtk() == false)
			return;
		ChangeImage(ImageManager::Instance()->BZ3_Attack());
		m_pstate = AI_State_Attack::Instance();
		return;
	case eSTATE::HIT:
		ChangeImage(ImageManager::Instance()->BZ3_Hit());
		m_pstate = AI_State_Hit::Instance();
		return;
	case eSTATE::MOVE:
		ChangeImage(ImageManager::Instance()->BZ3_Move());
		m_pstate = AI_State_Move::Instance();
		return;
	case eSTATE::STAY:
		ChangeImage(ImageManager::Instance()->BZ3_Stay());
		m_pstate = AI_State_Stay::Instance();
		return;
	case eSTATE::DEATH:
		ChangeImage(ImageManager::Instance()->BZ3_Death());
		m_pstate = AI_State_Death::Instance();
	}
}
