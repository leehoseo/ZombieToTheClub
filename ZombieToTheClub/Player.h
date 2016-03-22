#pragma once
#include "image.h"
#include "State.h"

class Player
{
private:
	Player();
	Image m_image;
	State * m_pstate;
public:
	
	static Player * Instance();
	~Player();

	void Initialize();

	void MoveX(float _x);
	void MoveY(float _y);

	void Move();
	void Update();
	void Render();

	void ChangeState(State * _newState);
	void ChangeImage(Image _image);

	int GetX() const;
	int GetY() const;
};

