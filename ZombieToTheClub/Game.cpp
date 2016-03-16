
#include "Game.h"
#include <stdio.h>
#include "ImageManager.h"

Game::Game()
	: m_frameCount( 0 )
{            
	m_startTime = timeGetTime();
	m_pgraphics = NULL;
	initialized = false;
}

Game::~Game()
{
	SAFE_DELETE(m_pgraphics);
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

	initialized = true;
}

void Game::renderGame()
{
	//start rendering
	if (SUCCEEDED(m_pgraphics->beginScene()))		// device의 백버퍼 비워주고 device3d->BeginScene(); -> sprite->Begin()순서로 실행
	{
		render();									// 함수 오버라이딩되어있다

		m_pgraphics->endScene();					// Scene을종료시킨다
	}

	m_pgraphics->showBackbuffer();					// 렌더링한 백버퍼를 보여준다
}

void Game::run(HWND hwnd)
{
	m_currentTime = timeGetTime() - m_startTime;

	++m_frameCount;
	
	if (60 > m_frameCount)					// 초당 프레임 60전까지 돌리다가 60프레임이 넘으면 실행X
	{
		if (m_pgraphics == NULL)
			return;

		update();
		renderGame();
	}

	if (1000 < m_currentTime )	// 1초가 지나면 카운트랑 시작시간 초기화
	{
		m_frameCount = 0;
		m_startTime = timeGetTime();
	}

	if (m_pgraphics == NULL)
		return;
}

	