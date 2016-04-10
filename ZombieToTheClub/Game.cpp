#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Scene_Play.h"
#include "Scene_TeamLogo.h"
#include "Time.h"
#include "Player.h"

Game::Game()
{            
	m_time.SetStartTime();
	m_pgraphics = NULL;
	m_sound = 0;
	initialized = false;
	srand(time(NULL));
}

Game::~Game()
{
	SAFE_DELETE(m_pgraphics);
	SAFE_DELETE(m_pscene);
	SAFE_DELETE(m_sound);
	initialized = false;             
}

bool Game::initialize(HWND hw)
{
	hwnd = hw;
	bool result = false;
	m_pgraphics = new Graphics();

	m_pgraphics->initialize(hwnd, GAME_WIDTH, GAME_HEIGHT, false);

	ImageManager::Instance()->initialize(m_pgraphics);
	m_pscene = new Scene_TeamLogo();
	m_pscene->Initialize();

	Sound::Instance()->Initialize(hwnd);

	initialized = true;
	return true;
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
		case WM_MOUSEMOVE:
			Mouse::Instance()->SetCoordiNate(lParam);
			return 0;
		case WM_LBUTTONDOWN:
			Mouse::Instance()->SetButtonClick(true);
			return 0;
		case WM_LBUTTONUP:
			Mouse::Instance()->SetButtonClick(false);
			return 0;
		case WM_KEYDOWN:
			return 0;
		}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}



void Game::renderGame()
{
	//start rendering
	if (SUCCEEDED(m_pgraphics->beginScene()))		// device의 백버퍼 비워주고 device3d->BeginScene(); -> sprite->Begin()순서로 실행
	{
		m_pscene->Update(this);
		m_pscene->Render(this);									// 함수 오버라이딩되어있다
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

int Game::GetScore() const
{
	return m_score;
}

// 점수 
void Game::AddScore(int _score)
{
	m_score += _score;
}

void Game::run()
{
	if (m_pgraphics == NULL)
		return;

	//printf("%d		%d\n", Mouse::Instance()->GetX(), Mouse::Instance()->GetY());
	m_time.SetTime();
	// 1/60초가 지나면 update()와 render 실행
	if (m_time.GetTime() > 16)			// 1000 : 1 = x : 1/60 공식으로 1/60초는 16.6666 
	{
		renderGame();

		m_time.SetStartTime();
	}
}