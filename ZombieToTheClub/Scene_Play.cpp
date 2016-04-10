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

	m_hiphop1.Initialize(ImageManager::Instance()->UI_Play_Hiphop1());
	m_hiphop2.Initialize(ImageManager::Instance()->UI_Play_Hiphop2());
	m_hiphop3.Initialize(ImageManager::Instance()->UI_Play_Hiphop3());
	m_leftHandStay = ImageManager::Instance()->LeftHandStay();
	m_rightHandStay= ImageManager::Instance()->RightHandStay();
	m_turnTable = ImageManager::Instance()->Play_TurnTable();
	m_interpace = ImageManager::Instance()->Play_Interpace();
	m_player = ImageManager::Instance()->Play_Player();
	m_floor = ImageManager::Instance()->Play_Floor();
	m_hpGage = ImageManager::Instance()->Play_HpGage();

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


	/*for (int index = 0; index < MAX_ZOMBIE; ++index)
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
	}*/
}


void Scene_Play::UI_Music_Check()
{
	if(m_hiphop1.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		printf("1\n");
		return;
	}

	if (m_hiphop2.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		printf("2\n");
		return;
	}

	if (m_hiphop3.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		printf("3\n");
		return;
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

	char combo[20];
	sprintf_s(combo, "COMBO : %d", Player::Instance()->GetCombo());
	LPCSTR Lcombo = combo;
	Text::Instaance()->Print(Lcombo, GAME_WIDTH - 200, 80);
}

void Scene_Play::CreateZombie()
{
	m_createTime.SetTime();

	if (m_currentStage != 0 &&
		m_currentZombie < m_stage[m_currentStage].maxZombie &&
		m_createTime.GetTime() > 1000 / m_stage[m_currentStage].createPerSecond)
	{
		m_pzombie[m_currentZombie] = new Boy_Zombie();

		if (rand() % 2)
		{
			m_pzombie[m_currentZombie]->initialize(rand() % (GAME_WIDTH - 148) + 10, rand() % 590, ImageManager::Instance()->BZ1_Stay(), AI_State_Stay::Instance());
		}
		else
		{
			m_pzombie[m_currentZombie]->initialize(rand() % (GAME_WIDTH - 148) + 10, rand() % 590, ImageManager::Instance()->BZ1_Move(), AI_State_Move::Instance());
		}

		++m_currentZombie;

		m_createTime.SetStartTime();
	}
}

void Scene_Play::StageStart()
{
	m_stageTime.SetTime();

	if (m_stageTime.GetTime() > m_stage[m_currentStage].time)		// Stage 가 시작되면
	{
		for (int index = 0; index < m_stage[m_currentStage].createZombie; ++index)		// 초기 좀비들 생성
		{
			m_pzombie[m_currentZombie] = new Boy_Zombie();

			if (rand() % 2)
			{
				m_pzombie[index]->initialize(rand() % (GAME_WIDTH - 148) + 10, rand() % 590, ImageManager::Instance()->BZ1_Stay(), AI_State_Stay::Instance());
			}
			else
			{
				m_pzombie[index]->initialize(rand() % (GAME_WIDTH - 148) + 10, rand() % 590, ImageManager::Instance()->BZ1_Move(), AI_State_Move::Instance());
			}

			++m_currentZombie;
		}

		m_stage[m_currentStage].bstageCheck = true;
		++m_currentStage;
		m_bgameStart = true;
	}
}

void Scene_Play::Update(Game* _game)
{	
	Player::Instance()->Update();
	m_hiphop1.Update();
	m_hiphop2.Update();
	m_hiphop3.Update();
	UI_Music_Check();
	m_leftHandStay.update(500);
	m_rightHandStay.update(500);
	
	StageStart();

	if (m_bgameStart == false)
		return;

	CreateZombie();

	for (int index = 0; index < m_currentZombie; ++index)
	{
		if (m_pzombie[index] == NULL)
			continue;

		m_pzombie[index]->Update();


		if (m_pzombie[index]->GetDeath())
		{
			_game->AddScore(m_pzombie[index]->GetScore());
			SAFE_DELETE(m_pzombie[index]);
			--m_currentZombie;
		}
	}

	_game->AddScore(m_currentStage);

	if (Player::Instance()->IsDie())
		_game->ChangeScene(new Scene_Score());
	
}

void Scene_Play::Render(Game* _game)
{
	m_interpace.draw();
	m_hiphop1.Render();
	m_hiphop2.Render();
	m_hiphop3.Render();
	
	m_turnTable.draw();
	m_player.draw();
	m_floor.draw();
	m_hpGage.draw();
	m_leftHandStay.draw();
	m_rightHandStay.draw();

	PrintStageInfo(_game);

	for (int index = 0; index < m_currentZombie; ++index)
	{
		if (m_pzombie[index] == NULL)
			continue;

		m_pzombie[index]->Render();
	}

	Player::Instance()->Render();
}
