#include "AI_State_Attack.h"
#include "AI_State_Stay.h"
#include "Zombie.h"
#include "ImageManager.h"
#include "Player.h"
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
	if (!AttackCheck(_zombie))
	{
		if (CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetHitCollisionBox(), _zombie->GetAttackCollisionBox()) && Player::Instance()->GetCode() != eSTATE::HIT)
		{
			Player::Instance()->Hit(*_zombie);
			Player::Instance()->ChangeState(eSTATE::HIT);
		}
		_zombie->SetIsAtk(false);
		_zombie->ChangeState(eSTATE::STAY);
	}
}

void AI_State_Attack::Attack(Zombie * _zombie)
{
}

bool AI_State_Attack::AttackCheck(Zombie * _zombie)
{
	if (_zombie->GetCurrentFrame() == _zombie->GetFrame())
	{
		return false;
	}
	return true;
}
