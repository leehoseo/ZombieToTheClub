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
	if (!HitCheck())
	{
		Player::Instance()->ChangeState(eSTATE::STAY);
	}
}

void State_Hit::Hit()
{

}

bool State_Hit::HitCheck()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}
