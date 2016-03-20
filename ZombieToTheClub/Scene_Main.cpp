#include "Scene_Main.h"
#include "Time.h"
#include "Game.h"
#include "Scene_Play.h"
#include <stdio.h>
Scene_Main::Scene_Main()
{
	Initialize();
}


Scene_Main::~Scene_Main()
{
}

void Scene_Main::Initialize()
{
	m_main = ImageManager::Instance()->Main();
	m_start.Initialize();
}

void Scene_Main::Update(Game * _game)
{
	/*if (m_start.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		_game->ChangeScene(new Scene_Play());
	}*/

	if (Mouse::Instance()->GetButtonClick())
	{
		m_start.SetImage(Mouse::Instance()->GetX(), Mouse::Instance()->GetY());
		printf("x : %d		y : %d\n", Mouse::Instance()->GetX(), Mouse::Instance()->GetY());
	}
}

void Scene_Main::Render()
{
	m_main.draw();
	m_start.Render();
	
}
