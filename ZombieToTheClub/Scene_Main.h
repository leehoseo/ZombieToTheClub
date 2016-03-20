#pragma once
#include "Scene.h"
#include "ImageManager.h"
#include "UI_Main_Start.h"

class Scene_Main	:	public Scene
{
private:
	Image m_main;
	UI_Main_Start m_start;

public:
	Scene_Main();
	~Scene_Main();

	virtual void Initialize();
	virtual void Update(Game* _game = 0);
	virtual void Render();

};

