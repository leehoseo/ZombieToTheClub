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
	UI m_hiphop1;
	UI m_hiphop2;
	UI m_hiphop3;

	Image m_leftHandStay;
	Image m_rightHandStay;

	Image m_turnTable;
	Image m_interpace;
	Image m_player;
	Image m_floor;
	Image m_hpGage;

	int m_currentStage;
	void UI_Music_Check();

	void CreateZombie();
	void StageStart();
	bool m_bgameStart;
public:

	Scene_Play();

	virtual ~Scene_Play();

	virtual void Update(Game* _game = 0);
	virtual void Render(Game* _game);
	virtual void Initialize();

	void PrintStageInfo(Game* _game);
};