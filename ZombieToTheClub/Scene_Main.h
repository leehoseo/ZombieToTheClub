#pragma once
#include "Scene.h"
#include "ImageManager.h"
#include "Zombie.h"

#include "UI.h"

class Scene_Main	:	public Scene
{
private:
	Zombie * m_pzombie[3];
	Image m_main;
	Image m_title;
	Image m_speak;
	Image m_clubEnterance;
	UI m_start;
	UI m_save;
	UI m_option;
	UI m_exit;

public:
	Scene_Main();
	~Scene_Main();

	virtual void Initialize();
	virtual void Update(Game* _game = 0);
	virtual void Render(Game* _game);
};

