#include "Scene_Play.h"

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
	m_zombie2.initialize();
}

void Scene_Play::Update(Game* _game)
{
	m_zombie2.SetX(m_zombie2.GetX() + 1);
}

void Scene_Play::Render()
{
	m_zombie.Render();
	m_zombie2.Render();
}