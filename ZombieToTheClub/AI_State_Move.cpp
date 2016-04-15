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
#include <math.h>


AI_State_Move::AI_State_Move()
{
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
	_zombie->Move();

	if (_zombie->Targeting() == true && _zombie->GetCode() != eSTATE::TRACE)
	{
		_zombie->ChangeState(eSTATE::TRACE);

	}

	if (_zombie->GetPatrolCount() == 3)
	{
		_zombie->ChangeState(eSTATE::STAY);
	}

	if (_zombie->GetCode() != eSTATE::HIT &&
		CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetHitCollisionBox(), _zombie->GetAttackCollisionBox()) &&
		_zombie->GetIsAtk() == true)
	{
		_zombie->ChangeState(eSTATE::ATTACK1);
	}
}