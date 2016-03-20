#include "Game.h"
#include <stdio.h>
#include <windows.h>
#include "Scene_Play.h"
#include "Scene_TeamLogo.h"
#include "Time.h"

Game::Game()
{            
	m_startTime = timeGetTime();

	m_pscene = new Scene_TeamLogo();

	m_pgraphics = NULL;
	initialized = false;
}

Game::~Game()
{
	SAFE_DELETE(m_pgraphics);
	SAFE_DELETE(m_pscene);
	initialized = false;             
}

LRESULT Game::messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (initialized)
	{
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void Game::initialize(HWND hw)
{
	hwnd = hw;                                

	m_pgraphics = new Graphics();

	m_pgraphics->initialize(hwnd, GAME_WIDTH, GAME_HEIGHT, false);

	ImageManager::Instance()->initialize(m_pgraphics);

	m_pscene->Initialize();

	initialized = true;
}

void Game::renderGame()
{
	//start rendering
	if (SUCCEEDED(m_pgraphics->beginScene()))		// device의 백버퍼 비워주고 device3d->BeginScene(); -> sprite->Begin()순서로 실행
	{
		m_pscene->Update(this);
		m_pscene->Render();									// 함수 오버라이딩되어있다

		m_pgraphics->endScene();					// Scene을종료시킨다
	}

	m_pgraphics->showBackbuffer();					// 렌더링한 백버퍼를 보여준다
}

void Game::ChangeScene(Scene * _newScene)
{
	delete m_pscene;
	// m_pscene = new _newScene();
	m_pscene = _newScene;
}

DWORD Game::GetRenderTime() const
{
	return m_renderTime;
}

void Game::run()
{
	if (m_pgraphics == NULL)
		return;

	Time::Instance()->SetTime();

	m_renderTime = timeGetTime();
	m_currentTime = timeGetTime() - m_startTime;
	
	// 1/60초가 지나면 update()와 render 실행
	if (m_currentTime > 16)			// 1000 : 1 = x : 1/60 공식으로 1/60초는 16.6666 
	{
		renderGame();

		m_startTime = timeGetTime();
	}
}