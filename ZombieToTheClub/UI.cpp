#include "UI.h"
#include "ImageManager.h"
#include "mouse.h"
#include <stdio.h>
#include "Sound.h"
UI::UI()
{
}


UI::~UI()
{
}

void UI::Initialize(Image _image)
{
	m_image = _image;
	m_isMouseIn = false;
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
	if (m_image.getX() < Mouse::Instance()->GetX() && Mouse::Instance()->GetX() < m_image.getX() + m_image.getWidth()
		&& m_image.getY() < Mouse::Instance()->GetY() && Mouse::Instance()->GetY() < m_image.getY() + m_image.getHeight())
	{
		if (false == m_isMouseIn)
		{
			Sound::Instance()->PlayButtonClick();
			m_isMouseIn = true;
		}
		temp.left = m_image.getPixelX();
		temp.right = m_image.getPixelX() * 2;
		temp.bottom = m_image.getPixelY();
		temp.top = 0;
		
		m_image.setSpriteDataRect(temp);
		return true;
	}
	else
	{
		temp.left = 0;
		temp.right = m_image.getPixelX();
		temp.bottom = m_image.getPixelY();
		temp.top = 0;
		m_isMouseIn = false;
		m_image.setSpriteDataRect(temp);
		return false;
	}
}

Image UI::GetImage()
{
	return m_image;
}
