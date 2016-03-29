#include "Scene_Play.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include "Boy_Zombie.h"
#include "AI_State_Move.h"
#include "AI_State_Stay.h"
#include "ImageManager.h"
#include "Boy_Zombie.h"
Scene_Play::Scene_Play()
{
	Initialize();
}

Scene_Play::~Scene_Play()
{    
	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		SAFE_DELETE(m_pzombie[index]);
	}
}

void Scene_Play::Initialize()
{
	int temp = 0;

	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		m_pzombie[index] = new Boy_Zombie();
		temp = rand() % 2;
		if (temp == 0)
			m_pzombie[index]->initialize(rand() % (GAME_WIDTH - 300), rand() % (GAME_HEIGHT - 300), ImageManager::Instance()->BZ_Stay(), AI_State_Stay::Instance());
		else
			m_pzombie[index]->initialize(rand() % (GAME_WIDTH - 300), rand() % (GAME_HEIGHT - 300), ImageManager::Instance()->BZ_Move(), AI_State_Move::Instance());
	}
}

void Scene_Play::Update(Game* _game)
{	
	Player::Instance()->Update();

	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		if (m_pzombie[index] == NULL)
			continue;

		m_pzombie[index]->Update();

		if (m_pzombie[index]->IsDie())
		{
			m_pzombie[index] = NULL;
			SAFE_DELETE(m_pzombie[index]);
		}
	}

	
}

void Scene_Play::Render()
{
	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		if (m_pzombie[index] != NULL)
			m_pzombie[index]->Render();

	}
	Player::Instance()->Render();
}
