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
		m_PatrolCount = 0;
		_zombie->ChangeState(eSTATE::HIT);
		
	}

	if (m_PatrolCount == 3)
	{
		m_PatrolCount = 0;
		_zombie->ChangeState(eSTATE::STAY);
		
	}

	if (_zombie->GetCode() != eSTATE::HIT &&
		CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetHitCollisionBox(), _zombie->GetAttackCollisionBox()) &&
		_zombie->GetIsAtk() == true )
	{
		_zombie->ChangeState(eSTATE::ATTACK);	
	}
}

void AI_State_Move::SetDirection(Zombie * _zombie)
{
	m_directionX = rand() % (GAME_WIDTH - 200);
	m_directionY = rand() % (GAME_HEIGHT - 200);

	/*if (0 > m_directionX || m_directionX > GAME_WIDTH - 200
		|| 0 > m_directionY || m_directionY > GAME_HEIGHT - 200)
		SetDirection(_zombie);*/

	m_isarrive = false;
}

void AI_State_Move::Move(Zombie * _zombie)
{
	if (m_isarrive == false)
	{
		if (_zombie->GetX() > m_directionX)	//	목적지가 왼쪽에있다면
			_zombie->MoveX(-3);
		else
			_zombie->MoveX(+3);

		if (_zombie->GetY() > m_directionY)	//	목적지가 위쪽
			_zombie->MoveY(-3);
		else
			_zombie->MoveY(+3);

		if (m_directionX - 10 < _zombie->GetX() && _zombie->GetX() < m_directionX + 10
			|| m_directionY - 10 < _zombie->GetY() && _zombie->GetX() < m_directionY + 10)
			m_isarrive = true;
	}
	else
	{
		SetDirection(_zombie);
		++m_PatrolCount;
	}
}
