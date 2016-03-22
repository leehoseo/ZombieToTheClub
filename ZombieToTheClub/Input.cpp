#include "Input.h"
#include <stdio.h>
#include "Player.h"
#include "Resource.h"

CInput::CInput()
{
	m_directInput = 0;
	m_keyboard = 0;
	m_mouse = 0;
	m_mouseX = 0;
	m_mouseY = 0;
}

CInput * CInput::Instance()
{
	static CInput instance;
	return &instance;
}

CInput::~CInput()
{
}

bool CInput::Initialize(HINSTANCE _hinstance, HWND _hwnd)
{
	HRESULT result;

	result = DirectInput8Create(_hinstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_directInput, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Initialize the direct input interface for the keyboard.
	result = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Set the data format.  In this case since it is a keyboard we can use the predefined data format.
	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
	{
		return false;
	}

	// Set the cooperative level of the keyboard to not share with other programs.
	result = m_keyboard->SetCooperativeLevel(_hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}

	// Now acquire the keyboard.
	result = m_keyboard->Acquire();
	if (FAILED(result))
	{
		return false;
	}

	// Initialize the direct input interface for the mouse.
	result = m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Set the data format for the mouse using the pre-defined mouse data format.
	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(result))
	{
		return false;
	}
	// Set the cooperative level of the mouse to share with other programs.
	result = m_mouse->SetCooperativeLevel(_hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}

	// Acquire the mouse.
	result = m_mouse->Acquire();
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

void CInput::Shutdown()
{
	// Release the mouse.
	if (m_mouse)
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}

	// Release the keyboard.
	if (m_keyboard)
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}

	// Release the main interface to direct input.
	if (m_directInput)
	{
		m_directInput->Release();
		m_directInput = 0;
	}

	return;
}

bool CInput::Update()
{
	bool result;


	// Read the current state of the keyboard.
	result = ReadKeyboard();
	if (!result)
	{
		return false;
	}

	//// Read the current state of the mouse.
	//result = ReadMouse();
	//if (!result)
	//{
	//	return false;
	//}

	// Process the changes in the mouse and keyboard.
	//KeyBoardPressed();
	return true;
}

bool CInput::ReadKeyboard()
{
	HRESULT result;


	// Read the keyboard device.
	result = m_keyboard->GetDeviceState(sizeof(m_keyboardState), (LPVOID)&m_keyboardState);

	if (FAILED(result))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			m_keyboard->Acquire();
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool CInput::ReadMouse()
{
	HRESULT result;

	// Read the mouse device.
	result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);

	if (FAILED(result))
	{
		// If the mouse lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			m_mouse->Acquire();
			
		}
		else
		{
			return false;
		}
	}
	
	return true;
}

int CInput::KeyBoardPressed()
{
	if (m_keyboardState[DIK_LEFT])
	{
		return DIK_LEFT;
	}

	if (m_keyboardState[DIK_RIGHT])
	{
		return DIK_RIGHT;
	}
	if (m_keyboardState[DIK_DOWN])
	{
		return DIK_DOWN;
	}
	if (m_keyboardState[DIK_UP])
	{
		return DIK_UP;
	}

	return 0;
}

bool CInput::KetPressedCheck(int _key)
{
	if (m_keyboardState[_key])
	{
		return true;
	}
	return false;
}
