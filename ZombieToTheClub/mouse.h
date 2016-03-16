#pragma once
#include <Windows.h>
#include <WindowsX.h>
class Mouse
{
private:
	POINT m_mouse;
public:
	Mouse();
	~Mouse();

	void SetMouseXY();

	int GetMouseX()	const;
	int GetMouseY()	const;
};

