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
	if (!HitCheck(_zombie))
	{
		m_time.SetTime();
		if (m_time.GetTime() > 600)
		{
			_zombie->SetCode(eSTATE::STAY);
			_zombie->ChangeImage(ImageManager::Instance()->BZ_Stay());
			_zombie->ChangeState(AI_State_Stay::Instance());
			m_time.SetStartTime();
		}
	}
}

bool AI_State_Hit::HitCheck(Zombie * _zombie)
{
	if (_zombie->GetCurrentFrame() == _zombie->GetFrame())
	{
		return false;
	}
	return true;
}
