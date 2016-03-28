#pragma once
class Zombie;

class AI_State
{
public:
	AI_State();
	~AI_State();

	virtual void Update(Zombie * _zombie) = 0;
};

