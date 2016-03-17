#pragma once

#define WIN32_LEAN_AND_MEAN

#include "Scene.h"
#include "image.h"
#include "Zombie.h"
#include "ImageManager_Play.h"

class Scene_Play : public Scene
{
private:
	Zombie * m_pzombie;
	Zombie * m_pzombie2;
public:
	// Constructor
	Scene_Play();

	// Destructor
	virtual ~Scene_Play();

	// Initialize the game
	virtual void Initialize();
	virtual void Update();     
	virtual void Render();     
};