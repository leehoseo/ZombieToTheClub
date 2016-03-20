#include "mouse.h"
Mouse::Mouse()
	: m_bbuttonClick(false)
{
}


Mouse::~Mouse()
{
}

Mouse * Mouse::Instance()
{
	static Mouse instance;
	return &instance;
}

void Mouse::SetCoordiNate(LPARAM _lParam)
{
	m_mouse.x = GET_X_LPARAM(_lParam);
	m_mouse.y = GET_Y_LPARAM(_lParam);
}


int Mouse::GetX() const
{
	return m_mouse.x;
}

int Mouse::GetY() const
{
	return m_mouse.y;
}

void Mouse::SetButtonClick(bool _check)
{
	m_bbuttonClick = _check;
}

bool Mouse::GetButtonClick()
{
	return m_bbuttonClick;
}
