#pragma once
#include "image.h"

class Player
{
private:
	Player();

	Image m_player;

public:
	
	static Player * Instance();
	~Player();

	void Initialize();

	void MoveX(float _x);
	void MoveY(float _y);

	void Move();
	void Update();
	void Render();
};

