#pragma once
#include "image.h"
#include "Resource.h"
#include "AI_State.h"

class Zombie
{
protected:
	Image m_image;
	Image m_test;

	eSTATE m_code;
	eTYPE m_type;

	AI_State * m_pstate;

	
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
	
	virtual void initialize(float _x , float _y , Image _image, AI_State *_state);
	virtual void Render();
	virtual void Update();
	virtual void SetX(float _x);
	virtual void SetY(float _y);
	virtual int GetX();
	virtual int GetY();
	virtual void Move();
	virtual void SetDirection();

	virtual bool Hit();

	virtual float GetRadius() const;

	float GetCenterX() const;
	float GetCenterY() const;

	int GetCode() const;

	void SetCode(eSTATE _code);

	void ChangeState(AI_State * _newState);
	void ChangeImage(Image _image);

	int GetCurrentFrame() const;
	int GetFrame() const;

	int GetType() const;

	Image GetImage() const;
};

