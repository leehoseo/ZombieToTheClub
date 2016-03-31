#include "AI_State_Stay.h"
#include "Zombie.h"
#include "ImageManager.h"
#include "AI_State_Hit.h"
#include "AI_State_Move.h"
#include "CrashCheck.h"
#include "Player.h"
AI_State_Stay::AI_State_Stay()
{
	m_time.SetStartTime();
}


AI_State_Stay * AI_State_Stay::Instance()
{
	static AI_State_Stay instance;
	return &instance;
}

AI_State_Stay::~AI_State_Stay()
{
}

void AI_State_Stay::Update(Zombie * _zombie)
{
	if (_zombie->Hit())
	{
		_zombie->ChangeState(eSTATE::HIT);
	}

	if (!StayCheck(_zombie))
	{
		_zombie->ChangeState(eSTATE::MOVE);
	}

	if (_zombie->GetCode() != eSTATE::HIT &&
		CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetHitCollisionBox(), _zombie->GetAttackCollisionBox()) &&
		_zombie->GetIsAtk() == true)
	{
		_zombie->ChangeState(eSTATE::ATTACK);
	}

}

bool AI_State_Stay::StayCheck(Zombie * _zombie)
{
	if (_zombie->GetCurrentFrame() == _zombie->GetFrame())
	{
		return false;
	}
	return true;
}