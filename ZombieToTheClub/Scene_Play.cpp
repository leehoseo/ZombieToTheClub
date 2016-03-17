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

void Scene_Play::Initialize()
{
	m_pzombie = new Zombie();
	m_pzombie2 = new Zombie();

	m_pzombie->initialize();
	m_pzombie2->initialize();
	
	return;
}

void Scene_Play::Update()
{
	
}

void Scene_Play::Render()
{
	m_pzombie2->GetImage()->setX(m_pzombie2->GetImage()->getX() + 1);
	m_pzombie->GetImage()->draw();
	m_pzombie2->GetImage()->draw();
}
