#include "UI.h"
#include "ImageManager.h"
#include "mouse.h"
#include <stdio.h>
UI::UI()
{
}


UI::~UI()
{
}

void UI::Initialize(Image _image)
{
	m_image = _image;
}

void UI::Render()
{
	m_image.draw();
}

void UI::Update()
{
}

bool UI::CollisionCheck()
{
	//printf("%f  %f	%d	%d\n", m_image.getX(), m_image.getY() , Mouse::Instance()->GetX() , Mouse::Instance()->GetY());
	if (m_image.getX() < Mouse::Instance()->GetX() && Mouse::Instance()->GetX() < m_image.getX() + m_image.getWidth()
		&& m_image.getY() < Mouse::Instance()->GetY() && Mouse::Instance()->GetY() < m_image.getY() + m_image.getHeight())
	{
		//printf("asdasdasd");
		return true;
	}
	return false;
}
