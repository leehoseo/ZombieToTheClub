#include "AI_State_Move.h"
#include "Zombie.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "ImageManager.h"
#include "AI_State_Hit.h"
#include "AI_State_Stay.h"

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
		_zombie->SetCode(eSTATE::HIT);
		_zombie->ChangeImage(ImageManager::Instance()->BZ_Hit());
		_zombie->ChangeState(AI_State_Hit::Instance());
		AI_State_Hit::Instance()->SetAniDelayTime();

		m_PatrolCount = 0;
	}

	if (m_PatrolCount == 3)
	{
		_zombie->SetCode(eSTATE::STAY);
		_zombie->ChangeImage(ImageManager::Instance()->BZ_Stay());
		_zombie->ChangeState(AI_State_Stay::Instance());
		AI_State_Stay::Instance()->SetAniDelayTime();
		m_PatrolCount = 0;
	}
}

void AI_State_Move::SetDirection(Zombie * _zombie)
{
	m_directionX = rand() % 800 + (_zombie->GetCenterX() - 400);
	m_directionY = rand() % 800 + (_zombie->GetCenterY() - 400);

	if (0 > m_directionX || m_directionX > GAME_WIDTH - 300
		|| 0 > m_directionY || m_directionY > GAME_HEIGHT - 300)
		return;

	m_isarrive = true;
	++m_PatrolCount;
}

void AI_State_Move::Move(Zombie * _zombie)
{
	if (m_isarrive)
	{
		if (_zombie->GetImage().getX() > m_directionX)	//	목적지가 왼쪽에있다면
			_zombie->SetX(-3);
		else
			_zombie->SetX(+3);

		if (_zombie->GetImage().getY() > m_directionY)	//	목적지가 위쪽
			_zombie->SetY(-3);
		else
			_zombie->SetY(+3);


		if (0 > _zombie->GetImage().getX() || _zombie->GetImage().getX() > GAME_WIDTH - 128
			|| 0 > _zombie->GetImage().getY() || _zombie->GetImage().getY() > GAME_HEIGHT - 128)
			m_isarrive = false;

		if (m_directionX - 20 < _zombie->GetImage().getX() && _zombie->GetImage().getX() < m_directionX + 20
			|| m_directionY - 20 < _zombie->GetImage().getY() && _zombie->GetImage().getX() < m_directionY + 20)
			m_isarrive = false;
	}
	else
	{
		SetDirection(_zombie);
	}
}
