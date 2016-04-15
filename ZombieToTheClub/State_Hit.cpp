#include "State_Hit.h"
#include "Player.h"
#include "ImageManager.h"
#include "State_Stay.h"

State_Hit::State_Hit()
{
}


State_Hit::~State_Hit()
{
}

void State_Hit::Update()
{
	if (!HitEnd())
	{
		Player::Instance()->ChangeState(eSTATE::STAY);
	}
}

bool State_Hit::HitEnd()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}
