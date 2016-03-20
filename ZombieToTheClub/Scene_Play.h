#pragma once

#define WIN32_LEAN_AND_MEAN

#include "Scene.h"
#include "image.h"
#include "Zombie.h"
#include "UI.h"

class Scene_Play : public Scene
{
private:
	Zombie	 m_zombie;
	Zombie	 m_zombie2;
public:

	Scene_Play();

	virtual ~Scene_Play();


	virtual void Update(Game* _game = 0);
	virtual void Render();  
	virtual void Initialize();
};