#include "AI_State_Move.h"
#include "Zombie.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "ImageManager.h"
#include "AI_State_Hit.h"
#include "AI_State_Stay.h"
#include "Player.h"
#include "CrashCheck.h"

AI_State_Move::AI_State_Move()
	:m_PatrolCount(0) , m_directionX(0) , m_directionY(0) , m_isarrive ( false)
{
	m_time.SetStartTime();
}

AI_State_Move::~AI_State_Move()
{
}

AI_State_Move * AI_State_Move::Instance()
{
	static AI_State_Move instance;

	return &instance;
}

void AI_State_Move::Update(Zombie * _zombie)
{
	Move(_zombie);

	if (_zombie->Hit())
	{
		_zombie->ChangeState(eSTATE::HIT);

		m_PatrolCount = 0;
	}

	if (m_PatrolCount == 3)
	{
		_zombie->ChangeState(eSTATE::STAY);
		m_PatrolCount = 0;
	}

	if (_zombie->GetCode() != eSTATE::HIT &&
		CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetCollisionBox(), _zombie->GetCollisionBox()) &&
		_zombie->GetIsAtk() == true )
	{
		_zombie->ChangeState(eSTATE::ATTACK);
	}

}

void AI_State_Move::SetDirection(Zombie * _zombie)
{
	_zombie->SetDirection();
	++m_PatrolCount;
}

void AI_State_Move::Move(Zombie * _zombie)
{
	_zombie->Move();
}
