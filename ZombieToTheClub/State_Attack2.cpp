#include "State_Attack2.h"
#include "Player.h"
#include "Resource.h"


State_Attack2::State_Attack2()
{
}


State_Attack2::~State_Attack2()
{
}

void State_Attack2::Update()
{
	Player::Instance()->AttackMove();

	if (!AttackEnd())
	{
		Player::Instance()->ChangeState(eSTATE::STAY);

		if (Player::Instance()->IsAttack())
		{
			Player::Instance()->ChangeState(eSTATE::ATTACK3);
		}
	}
}

bool State_Attack2::AttackEnd()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}
