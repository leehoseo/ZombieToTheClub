#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <Mmsystem.h>
#include "graphics.h"
#include "Resource.h"
#include "Scene.h"
#include "mouse.h"

class Game
{
protected:

	Graphics *m_pgraphics;       
	HWND    hwnd;             
	HRESULT hr;

	Scene* m_pscene;

	DWORD m_startTime;
	DWORD m_currentTime;

	DWORD m_renderTime;

	bool    initialized;

public:
	Game();
	virtual ~Game();

	LRESULT messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void initialize(HWND hwnd);

	void run();

	void renderGame();

	void ChangeScene(Scene* _newScene);

	DWORD GetRenderTime() const;
};