#pragma once
#include "Scene.h"
#include "image.h"

class Game;

class Scene_Score	:	public Scene
{
private:
	Image m_score;
public:
	Scene_Score();
	~Scene_Score();

	virtual void Render();
	virtual void Update(Game* _game = 0);
	virtual void Initialize();

};

