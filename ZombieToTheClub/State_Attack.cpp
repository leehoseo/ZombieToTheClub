#include "State_Attack.h"
#include "State_Stay.h"
#include "Player.h"
#include "ImageManager.h"
#include "Time.h"
#include "Resource.h"
State_Attack::State_Attack()
{
	//Player::Instance()->SetCode(eCODE::ATTACK);
}


State_Attack::~State_Attack()
{
}

void State_Attack::Update()
{
	Attack();
	if (!AttackCheck())
	{
		if (Time::Instance()->Timer(10))
		{
			Player::Instance()->SetCode(eCODE::STAY);
			Player::Instance()->ChangeImage(ImageManager::Instance()->Player_Stay());
			Player::Instance()->ChangeState(new State_Stay());
		}
	}
}

void State_Attack::Attack()
{
}

bool State_Attack::AttackCheck()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}
