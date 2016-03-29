#pragma once

#define WIN32_LEAN_AND_MEAN

#include "Scene.h"
#include "image.h"
#include "Zombie.h"
#include "Time.h"

#include "UI.h"

class Scene_Play : public Scene
{
private:
	Zombie * m_pzombie[MAX_ZOMBIE];
	Time m_time;
public:

	Scene_Play();

	virtual ~Scene_Play();

	virtual void Update(Game* _game = 0);
	virtual void Render();  
	virtual void Initialize();
};