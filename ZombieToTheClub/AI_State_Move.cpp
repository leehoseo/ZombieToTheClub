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
	srand(time(NULL));

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
	if (_zombie->Hit())
	{
		_zombie->SetCode(eSTATE::HIT);
		_zombie->ChangeImage(ImageManager::Instance()->BZ_Hit());
		_zombie->ChangeState(AI_State_Hit::Instance());
		m_PatrolCount = 0;
	}

	if (m_PatrolCount == 3)
	{
		_zombie->SetCode(eSTATE::STAY);
		_zombie->ChangeImage(ImageManager::Instance()->BZ_Stay());
		_zombie->ChangeState(AI_State_Stay::Instance());
		m_PatrolCount = 0;
	}

	Move(_zombie);
}

void AI_State_Move::SetDirection(Zombie * _zombie)
{
	m_directionX = (rand() % _zombie->GetImage().getWidth() * 4) + (_zombie->GetImage().getX() - (_zombie->GetImage().getWidth() * 2));
	m_directionY = (rand() % _zombie->GetImage().getHeight() * 4) + (_zombie->GetImage().getY() - (_zombie->GetImage().getHeight() * 2));
	m_isarrive = true;
	++m_PatrolCount;
}

void AI_State_Move::Move(Zombie * _zombie)
{
	printf("%d\n", m_directionX);
	if (m_isarrive)
	{
		if (_zombie->GetImage().getX() > m_directionX)	//	목적지가 왼쪽에있다면
			_zombie->SetX(-1);
		else
			_zombie->SetX(1);


		if (_zombie->GetImage().getY() > m_directionY)	//	목적지가 위쪽
			_zombie->SetY(-1);
		else
			_zombie->SetY(+1 );


		if (0 > _zombie->GetImage().getX() || _zombie->GetImage().getX() > GAME_WIDTH - 128
			|| 0 > _zombie->GetImage().getY() || _zombie->GetImage().getY() > GAME_HEIGHT - 128)
			m_isarrive = false;

		if (_zombie->GetImage().getX() == m_directionX || _zombie->GetImage().getY() == m_directionY)
			m_isarrive = false;
	}
	else
	{
		SetDirection(_zombie);
	}
}
