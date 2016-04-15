#include "State_Down.h"
#include "Player.h"

#include <stdio.h>


State_Down::State_Down()
{
}


State_Down::~State_Down()
{
}

void State_Down::Update()
{
	if (false == DownEnd())
	{
		Player::Instance()->ChangeState(eSTATE::STAY);
	}
}

bool State_Down::DownEnd()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}
