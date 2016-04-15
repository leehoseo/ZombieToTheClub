#pragma once

#define WIN32_LEAN_AND_MEAN

#include "Scene.h"
#include "image.h"
#include "Zombie.h"
#include "Time.h"
#include "UI.h"
#include "LeftHand.h"
#include "RightHand.h"
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
	Stage m_stage[7];
	Time m_stageTime;
	Time m_createTime;
	Time m_musicTime;
	Time m_bufMusicTime;
	int m_score;
	int m_currentZombie;
	int m_nKillZombie;
	bool m_bgameStart;
	
	UI m_hiphop1;
	UI m_hiphop2;
	UI m_hiphop3;
	LeftHand m_leftHand;
	RightHand m_rightHand;

	Image m_turnTable;
	Image m_interpace;
	Image m_player;
	Image m_floor;
	Image m_hpGage;

	int m_currentStage;

	void UI_Music_Check();
	void CreateZombie();
	void StageStart();
	void DecreaseHpGage();
	void Effect();

	int m_nMusicList[10];
	int m_nCurMusicList;

	bool m_isMusicHalf;
	bool m_isbufMusic;
public:

	Scene_Play();

	virtual ~Scene_Play();

	virtual void Update(Game* _game = 0);
	virtual void Render(Game* _game);
	virtual void Initialize();

	void ShuffleMusic();
	void PrintStageInfo(Game* _game);
	void ChangeMusic();
};