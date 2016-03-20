#pragma once
#include "Scene.h"
#include "ImageManager.h"
#include "image.h"
#include "Game.h"

class Scene_TeamLogo : public Scene
{
private:
	Image m_logo;
	int m_ibrightness;

	bool m_bfadeIn;

public:
	Scene_TeamLogo();
	~Scene_TeamLogo();

	virtual void Initialize();
	virtual void Update(Game* _game = 0);
	virtual void Render();
};

