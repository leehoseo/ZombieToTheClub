#include "Scene_Play.h"
#include "Player.h"

Scene_Play::Scene_Play()
{
	Initialize();
}

Scene_Play::~Scene_Play()
{    

}

void Scene_Play::Initialize()
{
	m_zombie.initialize();
}

void Scene_Play::Update(Game* _game)
{
	Player::Instance()->Update();
}

void Scene_Play::Render()
{
	m_zombie.Render();
	Player::Instance()->Render();
}