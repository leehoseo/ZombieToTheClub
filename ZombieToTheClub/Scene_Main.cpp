#include "Scene_Main.h"
#include "Time.h"
#include "Game.h"
#include "Scene_Play.h"
#include "Boy_Zombie.h"
#include "AI_State_Move.h"
#include <stdlib.h>
#include <time.h>


Scene_Main::Scene_Main()
{
	Initialize();
}


Scene_Main::~Scene_Main()
{
	for (int index = 0; index < 3; ++index)		// 초기 좀비들 생성
	{
		SAFE_DELETE(m_pzombie[index]);
	}
}

void Scene_Main::Initialize()
{
	m_main = ImageManager::Instance()->Main();
	m_start.Initialize(ImageManager::Instance()->UI_Main_Start());
	m_save.Initialize(ImageManager::Instance()->UI_Main_Save());
	m_option.Initialize(ImageManager::Instance()->UI_Main_Option());
	m_exit.Initialize(ImageManager::Instance()->UI_Main_Exit());
	m_title = ImageManager::Instance()->Title();
	for (int index = 0; index < 3 ; ++index)		// 초기 좀비들 생성
	{
		m_pzombie[index] = new Boy_Zombie();

		m_pzombie[index]->initialize( (rand() % GAME_WIDTH - 148) + 10 , (rand() % 120 + 640) + 10 , ImageManager::Instance()->BZ_Move(), AI_State_Move::Instance());
	}
}

void Scene_Main::Update(Game * _game)
{
	if (m_start.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		_game->ChangeScene(new Scene_Play());
		return;
	}

	if (m_save.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		_game->ChangeScene(new Scene_Play());
		return;
	}

	if (m_option.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		_game->ChangeScene(new Scene_Play());
		return;
	}

	if (m_exit.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		_game->ChangeScene(new Scene_Play());
		return;
	}


	for (int index = 0; index < 3; ++index)		// 초기 좀비들 생성
	{
		m_pzombie[index]->Update();
	}


	m_start.Update();
	m_save.Update();
	m_option.Update();
	m_exit.Update();

	m_title.update(200);
}

void Scene_Main::Render()
{
	m_main.draw();
	
	for (int index = 0; index < 3; ++index)		// 초기 좀비들 생성
	{
		m_pzombie[index]->Render();
	}

	m_title.draw();
	m_start.Render();
	m_save.Render();
	m_option.Render();
	m_exit.Render();
	

}
