#include "AI_State_Move.h"



AI_State_Move::AI_State_Move()
{
}


AI_State_Move::~AI_State_Move()
{
}

void AI_State_Move::Update(Zombie * _zombie)
{
	_zombie->SetDirection();
	_zombie->Move();
}

