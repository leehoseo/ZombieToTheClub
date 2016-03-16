

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include "Resource.h"
#include "Game.h"
#include "Scene_Play.h"
#include "mouse.h"
#include <stdio.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
bool CreateMainWindow(HWND &, HINSTANCE, int);
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);

HWND hwnd = NULL;
Game * game = NULL;
Mouse * mouse = NULL;
//=============================================================================
// Starting point for a Windows application
//=============================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	game = new Scene_Play();		// ó�� ������ Scene �����Ҵ�
	mouse = new Mouse();

	MSG msg;
	// Create the window
	if (!CreateMainWindow(hwnd, hInstance, nCmdShow))
		return 1;

	

	if (game == NULL)
		MessageBoxA(hwnd, "game Class ERROR", NULL, NULL);
	

	game->initialize(hwnd);

	int done = 0;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// look for quit message
			if (msg.message == WM_QUIT)
				done = 1;

			// decode and pass messages on to WinProc
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		game->run(hwnd);
	}
	return msg.wParam;

	SAFE_DELETE(game);
	SAFE_DELETE(mouse);

	DestroyWindow(hwnd);

	return 0;
}

//////////////////////////////////////////////
// wParam : ���콺�� ��ũ���� ���(11)
//          ����(0) , LB(1) , RB(2)
//			Ű���� �� �޾ƿ�
//			�Է� ����
//
// lParam : ���콺 ��ǥ
//			��ġ ����
//////////////////////////////////////////////

LRESULT WINAPI WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)		// Ű�Է�
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		MESSAGEBOX("LBOTTON DOWN");
		return 0;
	}
	mouse->SetMouseXY();

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

//=============================================================================
// Create the window
// Returns: false on error
//=============================================================================
bool CreateMainWindow(HWND &hwnd, HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcx;

	// Fill in the window class structure with parameters 
	// that describe the main window. 
	wcx.cbSize = sizeof(wcx);           // size of structure 
	wcx.style = CS_HREDRAW | CS_VREDRAW;    // redraw if size changes 
	wcx.lpfnWndProc = WinProc;          // points to window procedure 
	wcx.cbClsExtra = 0;                 // no extra class memory 
	wcx.cbWndExtra = 0;                 // no extra window memory 
	wcx.hInstance = hInstance;          // handle to instance 
	wcx.hIcon = NULL;
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);   // predefined arrow 
	wcx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);    // black background 
	wcx.lpszMenuName = NULL;           // name of menu resource 
	wcx.lpszClassName = GAME_NAME;     // name of window class 
	wcx.hIconSm = NULL;                 // small class icon 

										// Register the window class. 
										// RegisterClassEx returns 0 on error.
	if (RegisterClassEx(&wcx) == 0)    // if error
		return false;

	//set up the screen in windowed or fullscreen mode?
	DWORD style;
	
	style = WS_OVERLAPPEDWINDOW;

	// Create window
	hwnd = CreateWindow(
		GAME_NAME,             // name of the window class
		GAME_NAME,             // title bar text
		style,                  // window style
		CW_USEDEFAULT,          // default horizontal position of window
		CW_USEDEFAULT,          // default vertical position of window
		GAME_WIDTH,             // width of window
		GAME_HEIGHT,            // height of the window
		(HWND)NULL,            // no parent window
		(HMENU)NULL,           // no menu
		hInstance,              // handle to application instance
		(LPVOID)NULL);         // no window parameters

							   // if there was an error creating the window
	if (!hwnd)
		return false;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	return true;
}


