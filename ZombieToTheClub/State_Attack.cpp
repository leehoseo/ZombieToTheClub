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
	Attack();
	if (!AttackCheck())
	{
		Player::Instance()->ResetDirection();
		Player::Instance()->SetCode(eSTATE::STAY);
		Player::Instance()->ChangeImage(ImageManager::Instance()->Player_Stay());
		Player::Instance()->ChangeState(new State_Stay());
	}
}

void State_Attack::Attack()
{
	if (Player::Instance()->GetAttackDirection().m_direction[eDIRECTION::LEFT])
	{
		Player::Instance()->MoveX(-2);
		return;
	}

	else if (Player::Instance()->GetAttackDirection().m_direction[eDIRECTION::RIGHT])
	{
		Player::Instance()->MoveX(+2);
		return;
	}

	else if (Player::Instance()->GetAttackDirection().m_direction[eDIRECTION::UP])
	{
		Player::Instance()->MoveY(-2);
		return;
	}

	else if (Player::Instance()->GetAttackDirection().m_direction[eDIRECTION::DOWN])
	{
		Player::Instance()->MoveY(+2);
		return;
	}

	else if (Player::Instance()->GetAttackDirection().m_direction[eDIRECTION::LEFT_UP])
	{
		Player::Instance()->MoveX(-2);
		Player::Instance()->MoveY(-2);
		return;
	}

	else if (Player::Instance()->GetAttackDirection().m_direction[eDIRECTION::LEFT_DOWN])
	{
		Player::Instance()->MoveX(-2);
		Player::Instance()->MoveY(+2);
		return;
	}

	else if (Player::Instance()->GetAttackDirection().m_direction[eDIRECTION::RIGHT_UP])
	{
		Player::Instance()->MoveX(+2);
		Player::Instance()->MoveY(-2);
		return;
	}

	else if (Player::Instance()->GetAttackDirection().m_direction[eDIRECTION::RIGHT_DOWN])
	{
		Player::Instance()->MoveX(+2);
		Player::Instance()->MoveY(+2);
		return;
	}

	if (Player::Instance()->GetImage().GetHorizontal())
	{
		Player::Instance()->MoveX(-2);
	}
	else
	{
		Player::Instance()->MoveX(+2);
	}
}

bool State_Attack::AttackCheck()
{
	if (Player::Instance()->GetCurrentFrame() == Player::Instance()->GetFrame())
	{
		return false;
	}
	return true;
}