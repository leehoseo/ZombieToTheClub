#include "State_Attack.h"
#include "State_Stay.h"
#include "Player.h"
#include "ImageManager.h"
#include "Time.h"
#include "Resource.h"
State_Attack::State_Attack()
{
	m_time.SetStartTime();
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