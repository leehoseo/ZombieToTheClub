#include "mouse.h"



Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}

void Mouse::SetMouseXY()
{
	GetCursorPos(&m_mouse);
}


int Mouse::GetMouseX() const
{
	return m_mouse.x;
}

int Mouse::GetMouseY() const
{
	return m_mouse.y;
}
