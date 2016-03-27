#pragma once
#include "image.h"
#include "AI_State.h"

class Zombie
{
protected:
	Image m_image;
	Image m_test;

	int m_directionX;
	int m_directionY;
	bool m_isarrive;

	int m_hp;
	int m_atk;
	float m_moveSpeed;
	float atdSpeed;
	int m_experience;
	int m_score;

public:
	Zombie();
	~Zombie();
	
	virtual void initialize(float _x , float _y , Image _image);
	virtual void Render();
	virtual void Update();
	virtual void SetX(int _x);
	virtual void SetY(int _y);
	virtual int GetX();
	virtual int GetY();
	virtual void Move();
	virtual void SetDirection();

	virtual bool Hit();

	virtual float GetRadius() const;

	float GetCenterX() const;
	float GetCenterY() const;
};

