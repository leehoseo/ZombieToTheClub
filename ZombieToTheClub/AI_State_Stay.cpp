#include "AI_State_Stay.h"
#include "Zombie.h"
#include "ImageManager.h"
#include "AI_State_Hit.h"
#include "AI_State_Move.h"

AI_State_Stay::AI_State_Stay()
	:m_rest(false)
{
	m_time.SetStartTime();
}


AI_State_Stay * AI_State_Stay::Instance()
{
	static AI_State_Stay instance;
	return &instance;
}

AI_State_Stay::~AI_State_Stay()
{
}

void AI_State_Stay::Update(Zombie * _zombie)
{
	if (_zombie->Hit())
	{
		_zombie->SetCode(eSTATE::HIT);
		_zombie->ChangeImage(ImageManager::Instance()->BZ_Hit());
		_zombie->ChangeState(AI_State_Hit::Instance());
	}

	m_time.SetTime();
	if (m_time.GetTime() > 5000)
	{
		_zombie->SetCode(eSTATE::MOVE);
		_zombie->ChangeImage(ImageManager::Instance()->BZ_Move());
		_zombie->ChangeState(AI_State_Move::Instance());
		m_time.SetStartTime();
	}
}
