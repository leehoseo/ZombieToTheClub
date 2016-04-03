#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <Mmsystem.h>
#include "graphics.h"
#include "Resource.h"
#include "Scene.h"
#include "mouse.h"
#include "Time.h"
#include "Sound.h"

class Game
{
protected:
	Graphics *m_pgraphics;       
	HWND    hwnd;             
	HRESULT hr;
	Scene* m_pscene;
	Sound* m_sound;
	bool    initialized;
	Time m_time;
	int m_score;
public:
	Game();
	virtual ~Game();

	LRESULT messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	bool initialize(HWND hwnd);

	void run();

	void renderGame();

	void ChangeScene(Scene* _newScene);

	int GetScore() const;
	void SetScore(int _score);
};