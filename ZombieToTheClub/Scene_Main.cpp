#include "Scene_Main.h"
#include "Time.h"
#include "Game.h"
#include "Scene_Play.h"
#include <stdlib.h>
#include <time.h>

Scene_Main::Scene_Main()
	: m_bpatrol( false )
{
	Initialize();

	srand(time(NULL));
}


Scene_Main::~Scene_Main()
{
}

void Scene_Main::Initialize()
{
	m_zombie.initialize();
	m_main = ImageManager::Instance()->Main();
	m_start.Initialize(ImageManager::Instance()->UI_Main_Start());
	m_save.Initialize(ImageManager::Instance()->UI_Main_Save());
	m_option.Initialize(ImageManager::Instance()->UI_Main_Option());
	m_exit.Initialize(ImageManager::Instance()->UI_Main_Exit());
	m_title[0] = ImageManager::Instance()->Title()[0];
	m_title[1] = ImageManager::Instance()->Title()[1];
}

void Scene_Main::Update(Game * _game)
{
	if (m_start.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		_game->ChangeScene(new Scene_Play());
	}
}

void Scene_Main::Render()
{
	m_main.draw();
	m_start.Render();
	m_save.Render();
	m_option.Render();
	m_exit.Render();
}

void Scene_Main::Patrol()
{
	if (m_bpatrol == false)
	{

	}
}
