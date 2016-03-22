#pragma once
#include <dinput.h>

class CInput
{
private:
	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	unsigned char m_keyboardState[256];
	DIMOUSESTATE m_mouseState;

	int m_mouseX;
	int m_mouseY;
	CInput();
public:
	
	static CInput * Instance();
	~CInput();

	bool Initialize(HINSTANCE _hinstance, HWND _hwnd);
	void Shutdown();

	bool Update();
	bool ReadMouse();
	bool ReadKeyboard();
	int KeyBoardPressed();
	bool KetPressedCheck(int _key);
};

