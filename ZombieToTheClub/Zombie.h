#pragma once
#include "image.h"

class Zombie
{
protected:
	Image m_image;

	int m_directionX;
	int m_directionY;

	bool m_isarrive;
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
};

