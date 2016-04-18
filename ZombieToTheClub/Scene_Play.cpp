#include "Scene_Play.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include "Boy_Zombie1.h"
#include "Boy_Zombie2.h"
#include "Boy_Zombie3.h"
#include "AI_State_Move.h"
#include "AI_State_Stay.h"
#include "ImageManager.h"
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
	Sound::Instance()->ChangeMusic(m_nMusicList[m_nCurMusicList++]);

	m_currentStage = 0;
	m_currentZombie = 0;
	m_nKillZombie = 0;
	m_bgameStart = false;
	m_stageTime.SetStartTime();
	m_createTime.SetStartTime();
	m_musicTime.SetStartTime();
	m_bufMusicTime.SetStartTime();
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
	
	m_turnTable = ImageManager::Instance()->Play_TurnTable();
	m_interpace = ImageManager::Instance()->Play_Interpace();

	m_floor = ImageManager::Instance()->Play_Floor();
	m_hpGage = ImageManager::Instance()->Play_HpGage();
	m_razer = ImageManager::Instance()->Play_Razer();
	m_screenDoor = ImageManager::Instance()->Play_ScreenDoor();
	m_player = ImageManager::Instance()->Play_Player();
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
	ShuffleMusic();
	m_nCurMusicList = 0;
	m_isbufMusic = false;
	m_isMusicHalf = false;
}


void Scene_Play::UI_Music_Check()
{
	m_bufMusicTime.SetTime();

	if(m_hiphop1.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		m_isbufMusic = true;
		Sound::Instance()->ChangeBufMusic(0);
		return;
	}

	if (m_hiphop2.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		m_isbufMusic = true;
		Sound::Instance()->ChangeBufMusic(1);
		return;
	}

	if (m_hiphop3.CollisionCheck() && Mouse::Instance()->GetButtonClick())
	{
		m_isbufMusic = true;
		Sound::Instance()->ChangeBufMusic(2);
		return;
	}

	if (m_isbufMusic == false)
		return;

	if (m_bufMusicTime.GetTime() > Sound::Instance()->GetBufMusicEndTime())
	{
		m_isbufMusic = false;
		Sound::Instance()->ChangeMusic(m_nMusicList[m_nCurMusicList++]);
		m_bufMusicTime.SetStartTime();
	}
}

void Scene_Play::ShuffleMusic()
{
	for (int index = 0; index < 10; ++index)
		m_nMusicList[index] = index;

	int num1 = 0;
	int num2 = 0;
	int temp = 0;

	for (int index = 0; index < 30; ++index)
	{
		num1 = rand() % 10;
		num2 = rand() % 10;

		temp = m_nMusicList[num2];
		m_nMusicList[num2] = m_nMusicList[num1];
		m_nMusicList[num1] = temp;
	}
}

void Scene_Play::ChangeMusic()
{
	m_musicTime.SetTime();

	if (m_musicTime.GetTime() > Sound::Instance()->GetMusicEndTime() / 2 && m_isMusicHalf == false)
	{
		m_rightHand.ChangeAni(ImageManager::Instance()->RightHandHalfMusic());
		m_isMusicHalf = true;
	}

	if (m_musicTime.GetTime() > Sound::Instance()->GetMusicEndTime())
	{
		m_rightHand.ChangeAni(ImageManager::Instance()->RightHandMusicChange());
		Sound::Instance()->ChangeMusic(m_nMusicList[m_nCurMusicList++]);
		m_musicTime.SetStartTime();
		m_isMusicHalf = false;
	}

	if (m_nCurMusicList == 10)
	{
		m_nCurMusicList = 0;
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
		switch (rand() % 3)
		{
		case 0:
			m_pzombie[m_currentZombie] = new Boy_Zombie1();
			break;
		case 1:
			m_pzombie[m_currentZombie] = new Boy_Zombie2();
			break;
		case 2:
			m_pzombie[m_currentZombie] = new Boy_Zombie3();
			break;
		}

		m_pzombie[m_currentZombie]->initialize();
		
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
			switch (rand() % 3)
			{
			case 0:
				m_pzombie[m_currentZombie] = new Boy_Zombie1();
				break;
			case 1:
				m_pzombie[m_currentZombie] = new Boy_Zombie2();
				break;
			case 2:
				m_pzombie[m_currentZombie] = new Boy_Zombie3();
				break;
			}

			m_pzombie[index]->initialize();
		
			++m_currentZombie;
		}

		m_stage[m_currentStage].bstageCheck = true;
		++m_currentStage;
		m_bgameStart = true;
	}
}

void Scene_Play::DecreaseHpGage()
{
	RECT temp = { 0, 0, 0, 0 };
	temp.left = 0;
	temp.right = Player::Instance()->GetHp() * 3;
	temp.bottom = m_hpGage.getPixelY();
	temp.top = 0;
	m_hpGage.setSpriteDataRect(temp);
}

void Scene_Play::Effect()
{
	if (Player::Instance()->GetCombo() == 20 )
	{
		m_leftHand.ChangeAni(ImageManager::Instance()->LeftHandCombo());

		Sound::Instance()->Play20Combo();
	}

	if (Player::Instance()->GetCombo() == 50)
	{
		Sound::Instance()->Play50Combo();
	}

	if (Player::Instance()->GetCombo() == 100)
	{
		Sound::Instance()->Play100Combo();
	}

	if (Player::Instance()->GetCombo() == 150)
	{
		Sound::Instance()->Play150Combo();
	}

	if (Player::Instance()->GetCombo() != 0 && Player::Instance()->GetCombo() % 100 == 0)
	{
		Sound::Instance()->PlayGreatCombo();
	}

	if (m_nKillZombie != 0 && m_nKillZombie % 100 == 0 )
	{
		Sound::Instance()->Play100Kill();
	}
}

void Scene_Play::Update(Game* _game)
{	
	Player::Instance()->Update();
	m_hiphop1.Update();
	m_hiphop2.Update();
	m_hiphop3.Update();
	m_razer.update(500);
	m_leftHand.Update();
	m_rightHand.Update();
	
	DecreaseHpGage();
	StageStart();
	ChangeMusic();
	UI_Music_Check();
	Effect();

	if (m_screenDoor.GetCurrentFrame() != m_screenDoor.GetFrame())
	{
		m_screenDoor.update(200);
	}

	CreateZombie();

	for (int index = 0; index < m_currentZombie; ++index)
	{
		if (m_pzombie[index] == NULL)
			continue;

		m_pzombie[index]->Update();

		if (m_pzombie[index]->IsDeath())
		{
			_game->AddScore(m_pzombie[index]->GetScore());
			SAFE_DELETE(m_pzombie[index]);
			--m_currentZombie;
			++m_nKillZombie;
		}
	}

	_game->AddScore(m_currentStage);

	if (Player::Instance()->GetDeath())
		_game->ChangeScene(new Scene_Score());
	
}

void Scene_Play::Render(Game* _game)
{
	m_interpace.draw();
	m_hiphop1.Render();
	m_hiphop2.Render();
	m_hiphop3.Render();
	
	m_turnTable.draw();
	m_floor.draw();
	m_hpGage.draw();
	m_screenDoor.draw();
	m_leftHand.Render();
	m_rightHand.Render();
	m_player.draw();
	PrintStageInfo(_game);

	for (int index = 0; index < m_currentZombie; ++index)
	{
		if (m_pzombie[index] == NULL)
			continue;

		m_pzombie[index]->Render();
	}
	Player::Instance()->Render();
	m_razer.draw(D3DCOLOR_ARGB(150, 255, 255, 255));
}
