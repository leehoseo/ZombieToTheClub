#include "Scene_Play.h"
#include <stdio.h>
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
	m_zombie2.GetImage()->setX(m_zombie2.GetImage()->getX() + 1);
}

void Scene_Play::Render()
{
	m_zombie.GetImage()->draw();
	m_zombie2.GetImage()->draw();
}