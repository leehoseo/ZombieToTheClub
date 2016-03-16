#include "Scene_Play.h"

Scene_Play::Scene_Play()
{
	m_pzombie = NULL;
	m_pzombie2 = NULL;
}

Scene_Play::~Scene_Play()
{    
	SAFE_DELETE(m_pzombie);
	SAFE_DELETE(m_pzombie2);
}

void Scene_Play::initialize(HWND hwnd)
{
	m_pzombie = new Zombie();
	m_pzombie2 = new Zombie();

	Game::initialize(hwnd);

	m_pzombie->initialize();
	m_pzombie2->initialize();
	
	return;
}

void Scene_Play::update()
{
	
}

void Scene_Play::render()
{
	m_pzombie2->GetImage()->setX(m_pzombie2->GetImage()->getX() + 1);
	m_pzombie->GetImage()->draw();
	m_pzombie2->GetImage()->draw();
}
