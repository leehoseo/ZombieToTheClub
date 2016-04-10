#include "State_Attack3.h"
#include "Player.h"
#include "Resource.h"


State_Attack3::State_Attack3()
{
}


State_Attack3::~State_Attack3()
{
}
void State_Attack3::Update()
{
	Player::Instance()->AttackMove();

	if (!AttackEnd())
	{
		Player::Instance()->ChangeState(eSTATE::STAY);
	}
}

bool State_Attack3::AttackEnd()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}
