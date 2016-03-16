#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <Mmsystem.h>
#include "graphics.h"
#include "Resource.h"

class Game
{
protected:

	Graphics *m_pgraphics;       
	HWND    hwnd;             
	HRESULT hr;

	int m_frameCount;
       
	DWORD m_startTime;
	DWORD m_currentTime;

	bool    initialized;

public:
	Game();
	virtual ~Game();

	LRESULT messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	virtual void initialize(HWND hwnd);

	virtual void run(HWND);

	virtual void renderGame();
	virtual void update() = 0;
	virtual void render() = 0;
};