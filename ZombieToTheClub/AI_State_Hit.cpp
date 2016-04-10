#include "AI_State_Hit.h"
#include "ImageManager.h"
#include "AI_State_Stay.h"
#include "Zombie.h"
#include "Player.h"

AI_State_Hit::AI_State_Hit()
{
}


AI_State_Hit * AI_State_Hit::Instance()
{
	static AI_State_Hit instance;
	return &instance;
}

AI_State_Hit::~AI_State_Hit()
{
}

void AI_State_Hit::Update(Zombie * _zombie)
{
	if (AniEnd(_zombie) == false )
	{
		Player::Instance()->AddCombo(+1);
		Player::Instance()->SetComboTime();
		_zombie->SetHp(-Player::Instance()->GetAtk());
		_zombie->ChangeState(eSTATE::STAY);
	}
}

bool AI_State_Hit::AniEnd(Zombie * _zombie)
{
	if (_zombie->GetCurrentFrame() == _zombie->GetFrame())
	{
		return false;
	}
	return true;
}	