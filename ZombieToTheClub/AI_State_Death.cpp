#include "AI_State_Death.h"
#include "Zombie.h"
#include <stdio.h>

AI_State_Death::AI_State_Death()
{
}


void AI_State_Death::Update(Zombie * _zombie)
{
	if (AniEnd(_zombie) == false)
	{
		printf("efef");
		_zombie->SetDeath(true);
	}
}

AI_State_Death * AI_State_Death::Instance()
{
	static AI_State_Death instance;
	return &instance;
}

bool AI_State_Death::AniEnd(Zombie * _zombie)
{
	if (_zombie->GetCurrentFrame() == _zombie->GetFrame())
	{
		return false;
	}
	return true;
}

AI_State_Death::~AI_State_Death()
{
}
