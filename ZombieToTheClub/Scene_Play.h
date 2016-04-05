#pragma once

#define WIN32_LEAN_AND_MEAN

#include "Scene.h"
#include "image.h"
#include "Zombie.h"
#include "Time.h"

#include "UI.h"

struct Stage
{
	int time;
	int maxZombie;
	int createPerSecond;
	int createZombie;
	bool bstageCheck;
};

class Scene_Play : public Scene
{
private:
	Zombie * m_pzombie[MAX_ZOMBIE];
	Time m_stageTime;
	Time m_createTime;
	int m_score;
	int m_currentZombie;
	Stage m_stage[7];

	int m_currentStage;

	bool m_bgameStart;
public:

	Scene_Play();

	virtual ~Scene_Play();

	virtual void Update(Game* _game = 0);
	virtual void Render();  
	virtual void Initialize();

	void PrintStageInfo(Game* _game);
};