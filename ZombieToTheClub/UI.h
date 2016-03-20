#pragma once
#include "image.h"
#include "mouse.h"

class UI
{
protected:
	Image m_image;

public:
	UI();
	~UI();

	virtual void Initialize() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual bool CollisionCheck() = 0;
	virtual void SetImage(int _x, int _y) = 0;
};

