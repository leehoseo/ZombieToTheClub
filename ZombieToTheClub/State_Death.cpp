#include "State_Death.h"
#include "Player.h"



State_Death::State_Death()
{
}


State_Death::~State_Death()
{
}

void State_Death::Update()
{
	if (false == DeathEnd())
	{
		Player::Instance()->IsDie();
	}
}

bool State_Death::DeathEnd()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}
