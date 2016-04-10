#pragma once
#include "graphics.h"
#include "image.h"

class ImageManager
{
private:
	ImageManager();

	Image m_attackCollisionBox;
	Image m_hitCollisionBox;
	Image m_traceCollisionBox;
	// Logo 이미지
	Image m_teamlogo;

	// Main 배경
	Image m_main;
	Image m_title;

	// Main UI 모음
	Image m_ui_main_start;
	Image m_ui_main_save;
	Image m_ui_main_option;
	Image m_ui_main_exit;

	Image m_leftHandStay;
	Image m_rightHandStay;
	Image m_play_turnTable;
	Image m_play_interpace;
	Image m_play_player;
	Image m_play_floor;
	Image m_play_hpGage;
	// Play UI 모음
	Image m_ui_play_hiphop1;
	Image m_ui_play_hiphop2;
	Image m_ui_play_hiphop3;
	

	// Player
	Image m_player_move;
	Image m_player_stay;
	Image m_player_attack1;
	Image m_player_attack2;
	Image m_player_attack3;
	Image m_player_hit;

	Image m_bz1_stay;
	Image m_bz1_move;
	Image m_bz1_hit;
	Image m_bz1_attack;
	Image m_bz1_death;

	Image m_bz2_stay;
	Image m_bz2_move;
	Image m_bz2_hit;
	Image m_bz2_attack;
	Image m_bz2_death;

	Image m_bz3_stay;
	Image m_bz3_move;
	Image m_bz3_hit;
	Image m_bz3_attack;
	Image m_bz3_death;

	Image m_scone_score;

public:
	static ImageManager* Instance();

	virtual void initialize(Graphics* g);
	
	virtual ~ImageManager();

	Image AttackCollisionBox() const;
	Image HitCollisionBox() const;
	Image TraceCollsionBox() const;
	Image TeamLogo() const;
	Image Main() const;

	Image Title() const;

	Image UI_Main_Start() const;
	Image UI_Main_Save() const;
	Image UI_Main_Option() const;
	Image UI_Main_Exit() const;

	Image UI_Play_Hiphop1() const;
	Image UI_Play_Hiphop2() const;
	Image UI_Play_Hiphop3() const;
	Image Play_TurnTable() const;
	Image Play_Interpace() const;
	Image Play_Player() const;
	Image Play_Floor() const;
	Image Play_HpGage() const;

	Image LeftHandStay() const;
	Image RightHandStay() const;
	//Player
	Image Player_Move() const;
	Image Player_Stay() const;
	Image Player_Attack1() const;
	Image Player_Attack2() const;
	Image Player_Attack3() const;
	Image Player_Hit() const;

	Image BZ1_Stay() const;
	Image BZ1_Move() const;
	Image BZ1_Hit() const;
	Image BZ1_Attack() const;
	Image BZ1_Death() const;

	Image BZ2_Stay() const;
	Image BZ2_Move() const;
	Image BZ2_Hit() const;
	Image BZ2_Attack() const;
	Image BZ2_Death() const;

	Image BZ3_Stay() const;
	Image BZ3_Move() const;
	Image BZ3_Hit() const;
	Image BZ3_Attack() const;
	Image BZ3_Death() const;
	Image Scone_Score() const;
};

