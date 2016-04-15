#include "AI_State_Attack.h"
#include "AI_State_Stay.h"
#include "Zombie.h"
#include "ImageManager.h"
#include "Player.h"
#include <stdio.h>
AI_State_Attack::AI_State_Attack()
{
}


AI_State_Attack::~AI_State_Attack()
{
}

AI_State_Attack * AI_State_Attack::Instance()
{
	static AI_State_Attack instance;
	return &instance;
}

void AI_State_Attack::Update(Zombie * _zombie)
{
	if (AniEnd(_zombie) == false )
	{
		if (CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetHitCollisionBox(), _zombie->GetAttackCollisionBox()) && Player::Instance()->GetCode() != eSTATE::HIT &&  Player::Instance()->GetCode() != eSTATE::HIT_DOWN
			&& Player::Instance()->GetCode() != eSTATE::DEATH && true == Player::Instance()->GetHitAble())
		{
			Player::Instance()->ChangeState(eSTATE::HIT);
			Player::Instance()->Hit(*_zombie);
		}
		_zombie->SetIsAtk(false);
		_zombie->ChangeState(eSTATE::STAY);
	}
}

bool AI_State_Attack::AniEnd(Zombie * _zombie)
{
	if (_zombie->GetCurrentFrame() == _zombie->GetFrame())
	{
		return false;
	}
	return true;
}