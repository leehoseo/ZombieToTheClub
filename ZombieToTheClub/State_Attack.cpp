#include "State_Attack.h"
#include "Player.h"
#include "Resource.h"

State_Attack::State_Attack()
{
}


State_Attack::~State_Attack()
{
}

void State_Attack::Update()
{
	Player::Instance()->AttackMove();
	
	

	if (!AttackEnd())
	{
		Player::Instance()->ChangeState(eSTATE::STAY);

		if (Player::Instance()->IsAttack())
		{
			Player::Instance()->ChangeState(eSTATE::ATTACK2);
		}
	}
}

bool State_Attack::AttackEnd()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}