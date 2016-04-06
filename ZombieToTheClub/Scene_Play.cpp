#include "Scene_Play.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include "Boy_Zombie.h"
#include "AI_State_Move.h"
#include "AI_State_Stay.h"
#include "ImageManager.h"
#include "Boy_Zombie.h"
#include "CrashCheck.h"
#include "AI_State_Attack.h"
#include "Game.h"
#include "Scene_Main.h"
#include "Text.h"
#include <stdio.h>
#include "Scene_Score.h"

Scene_Play::Scene_Play()
{
	Initialize();

	Player::Instance()->Initialize();
	m_score = 0;
	Sound::Instance()->PlayLetsPatty();
	Sound::Instance()->PlayHiphop1();
	m_currentStage = 0;
	m_currentZombie = 0;
	m_bgameStart = false;
	m_stageTime.SetStartTime();
	m_createTime.SetStartTime();
}

Scene_Play::~Scene_Play()
{    
	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		SAFE_DELETE(m_pzombie[index]);
	}
}

void Scene_Play::Initialize()
{
	m_stage[0].time = 7000;
	m_stage[0].maxZombie = 50;
	m_stage[0].createPerSecond = 0;	 
	m_stage[0].createZombie = 15;
	m_stage[0].bstageCheck = false;

	m_stage[1].time = 10000;
	m_stage[1].maxZombie = 50;
	m_stage[1].createPerSecond = 1;
	m_stage[1].createZombie = 0;
	m_stage[1].bstageCheck = false;

	m_stage[2].time = 30000;
	m_stage[2].maxZombie = 50;
	m_stage[2].createPerSecond = 2;
	m_stage[2].createZombie = 0;
	m_stage[2].bstageCheck = false;

	m_stage[3].time = 60000;
	m_stage[3].maxZombie = 50;
	m_stage[3].createPerSecond = 4;
	m_stage[3].createZombie = 0;
	m_stage[3].bstageCheck = false;

	m_stage[4].time = 150000;
	m_stage[4].maxZombie = 100;
	m_stage[4].createPerSecond = 4;
	m_stage[4].createZombie = 30;
	m_stage[4].bstageCheck = false;

	m_stage[5].time = 200000;
	m_stage[5].maxZombie = 130;
	m_stage[5].createPerSecond = 4;
	m_stage[5].createZombie = 50;
	m_stage[5].bstageCheck = false;

	m_stage[6].time = 220000;
	m_stage[6].maxZombie = 150;
	m_stage[6].createPerSecond = 5;
	m_stage[6].createZombie = 0;
	m_stage[6].bstageCheck = false;


	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		m_pzombie[index] = new Boy_Zombie();
		
		if (rand() % 2)
		{
			m_pzombie[index]->initialize(-500, -500, ImageManager::Instance()->BZ_Stay(), AI_State_Stay::Instance());
		}
		else
		{
			m_pzombie[index]->initialize(-500, -500, ImageManager::Instance()->BZ_Move(), AI_State_Move::Instance());
		}
	}
}

void Scene_Play::PrintStageInfo(Game* _game)
{
	char stage[20];
	sprintf_s(stage, "Stage : %d", m_currentStage);
	LPCSTR Lstage = stage;
	Text::Instaance()->Print(Lstage, GAME_WIDTH - 200, 0);

	char score[20];
	sprintf_s(score, "Score : %d", _game->GetScore());
	LPCSTR Lscore = score;
	Text::Instaance()->Print(Lscore, GAME_WIDTH - 200, 20);

	char zombie[20];
	sprintf_s(zombie, "Zombie : %d", m_currentZombie);
	LPCSTR Lzombie = zombie;
	Text::Instaance()->Print(Lzombie, GAME_WIDTH - 200, 40);

	char hp[20];
	sprintf_s(hp, "HP : %d", Player::Instance()->GetHp());
	LPCSTR Lhp = hp;
	Text::Instaance()->Print(Lhp, GAME_WIDTH - 200, 60);
}


void Scene_Play::Update(Game* _game)
{	
	m_stageTime.SetTime();
	m_createTime.SetTime();

	PrintStageInfo(_game);
	Player::Instance()->Update();

	if (m_stageTime.GetTime() > m_stage[m_currentStage].time)		// Stage 가 시작되면
	{
		for (int index = 0; index < m_stage[m_currentStage].createZombie; ++index)		// 초기 좀비들 생성
		{
			m_pzombie[m_currentZombie]->SetCoordinate(rand() % (GAME_WIDTH - 148) + 10, rand() % (GAME_HEIGHT - 148) + 10);

			++m_currentZombie;
		}

		m_stage[m_currentStage].bstageCheck = true;
		++m_currentStage;
		m_bgameStart = true;
	}

	if (m_bgameStart == false)
		return;

	if( m_currentStage != 0 &&
		m_currentZombie < m_stage[m_currentStage].maxZombie &&
		m_createTime.GetTime() > 1000 / m_stage[m_currentStage].createPerSecond)
	{
		m_pzombie[m_currentZombie]->SetCoordinate(rand() % (GAME_WIDTH - 148) + 10, rand() % (GAME_HEIGHT - 148) + 10);
		++m_currentZombie;

		m_createTime.SetStartTime();
	}
	
	for (int index = 0; index < m_currentZombie ; ++index)
	{
		if (m_pzombie[index]->GetX() == - 500 || m_pzombie[index]->GetY() == - 500)
			continue;

		m_pzombie[index]->Update();

		if (m_pzombie[index]->IsDie())
		{
			_game->SetScore(+100);
			m_pzombie[index]->SetCoordinate(-500,-500);
			--m_currentZombie;
		}
	}
	_game->SetScore(+1);
	if (Player::Instance()->IsDie())
		_game->ChangeScene(new Scene_Score());
}

void Scene_Play::Render()
{
	for (int index = 0; index < m_currentZombie; ++index)
	{
		m_pzombie[index]->Render();
	}
	Player::Instance()->Render();
}
