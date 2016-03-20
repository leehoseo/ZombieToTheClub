#pragma once
#include "UI.h"
#include "image.h"

class UI_Main_Start	: public UI
{
private:
	Image m_image;
public:
	UI_Main_Start();
	~UI_Main_Start();

	virtual void Render();
	virtual void Update();
	virtual void Initialize();
	virtual bool CollisionCheck();
	virtual void SetImage(int _x, int _y);
};

