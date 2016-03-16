
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
	if (SUCCEEDED(m_pgraphics->beginScene()))		// device�� ����� ����ְ� device3d->BeginScene(); -> sprite->Begin()������ ����
	{
		render();									// �Լ� �������̵��Ǿ��ִ�

		m_pgraphics->endScene();					// Scene�������Ų��
	}

	m_pgraphics->showBackbuffer();					// �������� ����۸� �����ش�
}

void Game::run(HWND hwnd)
{
	m_currentTime = timeGetTime() - m_startTime;

	++m_frameCount;
	
	if (60 > m_frameCount)					// �ʴ� ������ 60������ �����ٰ� 60�������� ������ ����X
	{
		if (m_pgraphics == NULL)
			return;

		update();
		renderGame();
	}

	if (1000 < m_currentTime )	// 1�ʰ� ������ ī��Ʈ�� ���۽ð� �ʱ�ȭ
	{
		m_frameCount = 0;
		m_startTime = timeGetTime();
	}

	if (m_pgraphics == NULL)
		return;
}

	