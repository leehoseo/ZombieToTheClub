#pragma once

#define WIN32_LEAN_AND_MEAN

#include "Game.h"
#include "image.h"
#include "Zombie.h"
#include "ImageManager_Play.h"

class Scene_Play : public Game
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
	void initialize(HWND hwnd);
	void update();     
	void render();     
};