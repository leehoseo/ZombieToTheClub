#include "UI.h"
#include "ImageManager.h"
#include "mouse.h"

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
	if (m_image.getX() < Mouse::Instance()->GetX() && Mouse::Instance()->GetX() < m_image.getX() + m_image.getWidth()
		&& m_image.getY() < Mouse::Instance()->GetY() && Mouse::Instance()->GetY() < m_image.getY() + m_image.getHeight())
	{
		return true;
	}
	return false;
}
