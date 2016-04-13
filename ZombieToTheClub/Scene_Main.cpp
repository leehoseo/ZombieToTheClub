#include "Scene_Main.h"
#include "Time.h"
#include "Game.h"
#include "Scene_Play.h"
#include "Main_Zombie.h"
#include "AI_State_Move.h"
#include <stdlib.h>
#include <time.h>


Scene_Main::Scene_Main()
{
	Initialize();
	Sound::Instance()->PlayMusic();
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
		m_pzombie[index] = new Main_Zombie();

		m_pzombie[index]->initialize();
	}
}

void Scene_Main::Update(Game * _game)
{
	if (m_start.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		Sound::Instance()->EndMusic();
		_game->ChangeScene(new Scene_Play());
		return;
	}

	if (m_save.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		Sound::Instance()->EndMusic();
		_game->ChangeScene(new Scene_Play());
		return;
	}

	if (m_option.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		Sound::Instance()->EndMusic();
		_game->ChangeScene(new Scene_Play());
		return;
	}

	if (m_exit.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		PostQuitMessage(0);
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

void Scene_Main::Render(Game* _game)
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
