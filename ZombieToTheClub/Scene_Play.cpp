#include "Scene_Play.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include "Boy_Zombie.h"
#include "ImageManager.h"
Scene_Play::Scene_Play()
{
	srand(time(NULL));
	Initialize();
}

Scene_Play::~Scene_Play()
{    
}

void Scene_Play::Initialize()
{
	for (int index = 0; index < MAX_ZOMBIE; ++index)
		m_pzombie[index].initialize(rand() % (GAME_WIDTH - 128), rand() % (GAME_HEIGHT - 128), ImageManager::Instance()->Zombie_1());
	
}

void Scene_Play::Update(Game* _game)
{	
	Player::Instance()->Update();

	for (int index = 0; index < MAX_ZOMBIE; ++index)
		m_pzombie[index].Update();
}

void Scene_Play::Render()
{
	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		m_pzombie[index].Render();

	}
	Player::Instance()->Render();
}
