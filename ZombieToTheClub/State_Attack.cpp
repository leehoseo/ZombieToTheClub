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
		/*m_time.SetTime();
		if (m_time.GetTime() > 600)
		{*/
			Player::Instance()->SetCode(eSTATE::STAY);
			Player::Instance()->ChangeImage(ImageManager::Instance()->Player_Stay());
			Player::Instance()->ChangeState(new State_Stay());
			/*m_time.SetStartTime();
		}*/
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