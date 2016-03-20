#include "Scene_TeamLogo.h"
#include "ImageManager.h"
#include "Scene_Main.h"
#include "Time.h"

Scene_TeamLogo::Scene_TeamLogo()
{
}


Scene_TeamLogo::~Scene_TeamLogo()
{
}

void Scene_TeamLogo::Initialize()
{
	m_logo = ImageManager::Instance()->TeamLogo();
}

void Scene_TeamLogo::Update(Game* _game)
{
	if (ImageManager::Instance()->IsInitialized() && Time::Instance()->Timer(3000))
	{
		_game->ChangeScene(new Scene_Main());
	}
}

void Scene_TeamLogo::Render()
{
	m_logo.draw();
}