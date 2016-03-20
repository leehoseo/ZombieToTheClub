#include "UI_Main_Start.h"
#include "ImageManager.h"
#include <stdio.h>

UI_Main_Start::UI_Main_Start()
{
	
}


UI_Main_Start::~UI_Main_Start()
{
}

void UI_Main_Start::Render()
{
	m_image.draw();
}

void UI_Main_Start::Update()
{
}

void UI_Main_Start::Initialize()
{
	m_image = ImageManager::Instance()->UI_Main_Start();
}

bool UI_Main_Start::CollisionCheck()
{
	
	if (m_image.getSpriteDataRect().left < Mouse::Instance()->GetX() && Mouse::Instance()->GetX() < m_image.getSpriteDataRect().right
		&& m_image.getSpriteDataRect().top < Mouse::Instance()->GetY() && Mouse::Instance()->GetY() < m_image.getSpriteDataRect().bottom)
	{
		return true;
	}
	return false;
}

void UI_Main_Start::SetImage(int _x, int _y)
{
	m_image.setX(_x);
	m_image.setY(_y);
}

