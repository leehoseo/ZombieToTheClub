#include "Scene_Play.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include "Boy_Zombie.h"
#include "AI_State_Move.h"
#include "AI_State_Stay.h"

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
	int temp = 0;
	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		temp = rand() % 2;
		if(temp == 0)
			m_pzombie[index].initialize(rand() % (GAME_WIDTH - 128), rand() % (GAME_HEIGHT - 128), ImageManager::Instance()->BZ_Stay(), AI_State_Stay::Instance());
		else
			m_pzombie[index].initialize(rand() % (GAME_WIDTH - 128), rand() % (GAME_HEIGHT - 128), ImageManager::Instance()->BZ_Move(), AI_State_Move::Instance());
	}
	
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
