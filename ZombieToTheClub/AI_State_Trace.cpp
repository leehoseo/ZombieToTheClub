#include "AI_State_Trace.h"
#include "Player.h"
#include "Zombie.h"

AI_State_Trace::AI_State_Trace()
{
}

AI_State_Trace::~AI_State_Trace()
{
}

AI_State_Trace * AI_State_Trace::Instance()
{
	static AI_State_Trace instance;
	return &instance;
}

void AI_State_Trace::Update(Zombie * _zombie)
{
	_zombie->SetDirection(Player::Instance()->GetX(), Player::Instance()->GetY());
	_zombie->Move();

	if (false == _zombie->Tracing())
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