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
	Sound::Instance()->PlayHiphop1();
	//Sound::Instance()->PlayHiphop2();
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

	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		m_pzombie[index] = new Boy_Zombie();

		if (rand() % 2)
			m_pzombie[index]->initialize(rand() % (GAME_WIDTH - 128), rand() % (GAME_HEIGHT - 128), ImageManager::Instance()->BZ_Stay(), AI_State_Stay::Instance());
		else
			m_pzombie[index]->initialize(rand() % (GAME_WIDTH - 128), rand() % (GAME_HEIGHT - 128), ImageManager::Instance()->BZ_Move(), AI_State_Move::Instance());
	}
}

void Scene_Play::Update(Game* _game)
{	
	Player::Instance()->Update();
	char buffer[20];
	sprintf_s(buffer, "score : %d", m_score);
	LPCSTR p = buffer;

	Text::Instaance()->Print(p, GAME_WIDTH - 200, 0);

	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		if (m_pzombie[index] == NULL)
			continue;
	
		// 플레이어 맞음
		if (CrashCheck::Instance()->Rect_Rect(Player::Instance()->GetHitCollisionBox(), m_pzombie[index]->GetAttackCollisionBox()) && m_pzombie[index]->GetCode() != eSTATE::ATTACK)
		{
			
			m_pzombie[index]->SetCode(eSTATE::ATTACK);
		}

		m_pzombie[index]->Update();

		if (m_pzombie[index]->IsDie())
		{
			_game->SetScore(+100);
			m_pzombie[index] = NULL;
		}

	}

	_game->SetScore(+1);
	if (Player::Instance()->IsDie())
		_game->ChangeScene(new Scene_Score());

}

void Scene_Play::Render()
{
	for (int index = 0; index < MAX_ZOMBIE; ++index)
	{
		if (m_pzombie[index] != NULL)
			m_pzombie[index]->Render();
	}
	Player::Instance()->Render();
}
