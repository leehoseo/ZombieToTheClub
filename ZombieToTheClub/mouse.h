#pragma once
#include <Windows.h>
#include <WindowsX.h>
#
class Mouse
{
private:
	POINT m_mouse;
	bool m_bbuttonClick;

	Mouse();
public:
	~Mouse();

	static Mouse* Instance();

	void SetCoordiNate(LPARAM _lParam);

	int GetX()	const;
	int GetY()	const;

	void SetButtonClick(bool _check);
	bool GetButtonClick();
};

