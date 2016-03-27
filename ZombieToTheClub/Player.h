#pragma once
#include "image.h"
#include "State.h"

class Player
{
private:

	Player();
	Image m_image;
	Image m_test;
	State * m_pstate;
	eCODE m_code;

	int m_atk;
	int m_hp;
	float m_moveSpeed;
	float m_atkSpeed;
	int m_gold;
	int m_experience;

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

	int GetCurrentFrame() const;
	int GetFrame() const;

	int GetCode() const;

	void SetCode(eCODE _code);

	float GetRadius() const;

	float GetCenterX() const;
	float GetCenterY() const;

	int GetAtk() const;
};

