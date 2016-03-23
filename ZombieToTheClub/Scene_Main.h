#pragma once
#include "Scene.h"
#include "ImageManager.h"
#include "Zombie.h"

#include "UI.h"

class Scene_Main	:	public Scene
{
private:

	Image m_main;
	Image m_title;
	UI m_start;
	UI m_save;
	UI m_option;
	UI m_exit;

	bool m_bpatrol;
public:
	Scene_Main();
	~Scene_Main();

	virtual void Initialize();
	virtual void Update(Game* _game = 0);
	virtual void Render();
};

