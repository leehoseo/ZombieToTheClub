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
	m_image.update(0);
}

bool UI::CollisionCheck()
{
	RECT temp = { 0, 0, 0, 0 };
	//printf("%f  %f	%d	%d\n", m_image.getX(), m_image.getY() , Mouse::Instance()->GetX() , Mouse::Instance()->GetY());
	if (m_image.getX() < Mouse::Instance()->GetX() && Mouse::Instance()->GetX() < m_image.getX() + m_image.getWidth()
		&& m_image.getY() < Mouse::Instance()->GetY() && Mouse::Instance()->GetY() < m_image.getY() + m_image.getHeight())
	{
		temp.left = 408;
		temp.right = 816;
		temp.bottom = 95;
		temp.top = 0;

		m_image.setSpriteDataRect(temp);
		return true;
	}
	else
	{
		temp.left = 0;
		temp.right = 408;
		temp.bottom = 95;
		temp.top = 0;

		m_image.setSpriteDataRect(temp);
		return false;
	}
}

Image UI::GetImage()
{
	return m_image;
}
