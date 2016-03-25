#include "State_Attack.h"
#include "State_Stay.h"
#include "Player.h"
#include "ImageManager.h"

State_Attack::State_Attack()
{
}


State_Attack::~State_Attack()
{
}

void State_Attack::Update()
{
	if (!AttackCheck())
	{
		Player::Instance()->ChangeImage(ImageManager::Instance()->Player_Stay());
		Player::Instance()->ChangeState(new State_Stay());
	}
}

void State_Attack::Attack()
{

}

bool State_Attack::AttackCheck()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame()-1)
	{
		return false;
	}
	return true;
}
