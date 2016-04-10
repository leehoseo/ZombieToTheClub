#include "Scene_Score.h"
#include <stdio.h>
#include "Text.h"
#include "ImageManager.h"
#include "Game.h"

Scene_Score::Scene_Score()
{
	Initialize();
}

void Scene_Score::Initialize()
{
	m_score = ImageManager::Instance()->Scone_Score();
}


Scene_Score::~Scene_Score()
{
}

void Scene_Score::Render(Game* _game)
{
	//m_score.draw();
}

void Scene_Score::Update(Game * _game)
{
	char buffer[20];
	sprintf_s(buffer, "score : %d", _game->GetScore());
	LPCSTR p = buffer;

	Text::Instaance()->Print(p, GAME_WIDTH/2, GAME_HEIGHT/2);
}

