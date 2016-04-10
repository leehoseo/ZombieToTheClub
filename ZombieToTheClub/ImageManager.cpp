#include "ImageManager.h"
#include "Resource.h"


ImageManager::ImageManager()
{

}

ImageManager::~ImageManager()
{
}

ImageManager* ImageManager::Instance()
{
	static ImageManager instance;

	return &instance;
}

void ImageManager::initialize(Graphics * g)
{
	m_teamlogo.initialize(g, 0, 0, GAME_WIDTH / 2 - 150, GAME_HEIGHT / 2 - 100, 0, "../ZombieToTheClub\\Resource\\TeamLogo.png");

	m_title.initialize(g, 800, 240, 218, 50, 2, "../ZombieToTheClub\\Resource\\Title.png");

	m_attackCollisionBox.initialize(g, 0, 0, 0, 0, 0, "../ZombieToTheClub\\Resource\\Attack_CollisionBox.png");
	m_hitCollisionBox.initialize(g, 0, 0, 0, 0, 0, "../ZombieToTheClub\\Resource\\Hit_CollisionBox.png");
	m_traceCollisionBox.initialize(g, 0, 0, 0, 0, 0, "../ZombieToTheClub\\Resource\\Trace_CollisionBox.png");

	// Main 이미지
	m_main.initialize(g, 0, 0, 0, 0, 0, "../ZombieToTheClub\\Resource\\Main.png");
	m_ui_main_start.initialize(g, 408, 95, 1160, 450, 0, "../ZombieToTheClub\\Resource\\Start.png");
	m_ui_main_save.initialize(g, 408, 95, 1160, 550, 0, "../ZombieToTheClub\\Resource\\Save.png");
	m_ui_main_option.initialize(g, 408, 95, 1160, 650, 0, "../ZombieToTheClub\\Resource\\Option.png");
	m_ui_main_exit.initialize(g, 408, 95, 1160, 750, 0, "../ZombieToTheClub\\Resource\\Exit.png");

	m_ui_play_hiphop1.initialize(g, 350 ,40 , 1208, 740, 0, "../ZombieToTheClub\\Resource\\MosicButton.png");
	m_ui_play_hiphop2.initialize(g, 350 ,40 , 1208, 795, 0, "../ZombieToTheClub\\Resource\\MosicButton.png");
	m_ui_play_hiphop3.initialize(g, 350 ,40 , 1208, 850, 0, "../ZombieToTheClub\\Resource\\MosicButton.png");

	m_play_turnTable.initialize(g, 0, 0, 464, 740, 0, "../ZombieToTheClub\\Resource\\TurnTable.png");
	m_play_interpace.initialize(g, 0, 0, 0, 740, 0, "../ZombieToTheClub\\Resource\\Interpace.png");
	m_play_player.initialize(g, 0, 0, 41, 740, 0, "../ZombieToTheClub\\Resource\\Player.png");
	m_play_floor.initialize(g, 0, 0, 0, 0, 0, "../ZombieToTheClub\\Resource\\Floor.png");
	m_play_hpGage.initialize(g, 0, 0, 118, 790, 0, "../ZombieToTheClub\\Resource\\HpGage.png");
	
	m_leftHandStay.initialize(g, 280, 233, 464, 624, 2, "../ZombieToTheClub\\Resource\\LeftHand_Stay.png");
	m_rightHandStay.initialize(g, 280, 233, 800, 624, 2, "../ZombieToTheClub\\Resource\\RightHand_Stay.png");

	//Player
	m_player_move.initialize(g, 128, 128, 0, 0, 10, "../ZombieToTheClub\\Resource\\Player_Move.png");
	m_player_stay.initialize(g, 128, 128, 0, 0, 2, "../ZombieToTheClub\\Resource\\Player_Stay.png");
	m_player_attack.initialize(g, 128, 128, 0, 0, 3, "../ZombieToTheClub\\Resource\\Player_Attack.png");
	m_player_hit.initialize(g, 128, 128, 0, 0, 3, "../ZombieToTheClub\\Resource\\Player_Down.png");

	m_bz1_stay.initialize(g, 128, 128, 0, 0, 6, "../ZombieToTheClub\\Resource\\Zombie\\Boy_Zombie1\\bz1_stay.png");
	m_bz1_move.initialize(g, 128, 128, 0, 0, 4, "../ZombieToTheClub\\Resource\\Zombie\\Boy_Zombie1\\bz1_move.png");
	m_bz1_hit.initialize(g, 128, 128, 0, 0, 3, "../ZombieToTheClub\\Resource\\Zombie\\Boy_Zombie1\\bz1_hit.png");
	m_bz1_attack.initialize(g, 128, 128, 0, 0, 4, "../ZombieToTheClub\\Resource\\Zombie\\Boy_Zombie1\\bz1_attack.png");
	m_bz1_death.initialize(g, 128, 128, 0, 0, 10, "../ZombieToTheClub\\Resource\\Zombie\\Boy_Zombie1\\bz1_death.png");

	m_scone_score.initialize(g, 0, 0, 0, 0, 0, "../ZombieToTheClub\\Resource\\Score.png");
}

Image ImageManager::BZ1_Stay() const
{
	return m_bz1_stay;
}

Image ImageManager::BZ1_Move() const
{
	return m_bz1_move;
}

Image ImageManager::BZ1_Hit() const
{
	return m_bz1_hit;
}

Image ImageManager::BZ1_Attack() const
{
	return m_bz1_attack;
}

Image ImageManager::BZ1_Death() const
{
	return m_bz1_death;
}

Image ImageManager::BZ2_Stay() const
{
	return m_bz2_stay;
}

Image ImageManager::BZ2_Move() const
{
	return m_bz2_move;
}

Image ImageManager::BZ2_Hit() const
{
	return m_bz2_hit;
}

Image ImageManager::BZ2_Attack() const
{
	return m_bz2_attack;
}

Image ImageManager::BZ2_Death() const
{
	return m_bz2_death;
}

Image ImageManager::BZ3_Stay() const
{
	return m_bz3_stay;
}

Image ImageManager::BZ3_Move() const
{
	return m_bz3_move;
}

Image ImageManager::BZ3_Hit() const
{
	return m_bz3_hit;
}

Image ImageManager::BZ3_Attack() const
{
	return m_bz3_attack;
}

Image ImageManager::BZ3_Death() const
{
	return m_bz3_death;
}

Image ImageManager::Scone_Score() const
{
	return m_scone_score;
}

Image ImageManager::TeamLogo() const 
{
	return m_teamlogo;
}

// Main 이미지 UI
Image ImageManager::Main() const
{
	return m_main;
}

Image ImageManager::UI_Main_Start() const
{
	return m_ui_main_start;
}

Image ImageManager::UI_Main_Save() const
{
	return m_ui_main_save;
}

Image ImageManager::UI_Main_Option() const
{
	return m_ui_main_option;
}

Image ImageManager::UI_Main_Exit() const
{
	return m_ui_main_exit;
}

Image ImageManager::UI_Play_Hiphop1() const
{
	return m_ui_play_hiphop1;
}

Image ImageManager::UI_Play_Hiphop2() const
{
	return m_ui_play_hiphop2;
}

Image ImageManager::UI_Play_Hiphop3() const
{
	return m_ui_play_hiphop3;
}

Image ImageManager::Play_TurnTable() const
{
	return m_play_turnTable;
}

Image ImageManager::Play_Interpace() const
{
	return m_play_interpace;
}

Image ImageManager::Play_Player() const
{
	return m_play_player;
}

Image ImageManager::Play_Floor() const
{
	return m_play_floor;
}

Image ImageManager::Play_HpGage() const
{
	return m_play_hpGage;
}

Image ImageManager::LeftHandStay() const
{
	return m_leftHandStay;
}

Image ImageManager::RightHandStay() const
{
	return m_rightHandStay;
}

Image ImageManager::Player_Move() const
{
	return m_player_move;
}

Image ImageManager::Player_Stay() const
{
	return m_player_stay;
}

Image ImageManager::Player_Attack() const
{
	return m_player_attack;
}

Image ImageManager::Player_Hit() const
{
	return m_player_hit;
}

Image ImageManager::AttackCollisionBox() const
{
	return m_attackCollisionBox;
}

Image ImageManager::HitCollisionBox() const
{
	return m_hitCollisionBox;
}

Image ImageManager::TraceCollsionBox() const
{
	return m_traceCollisionBox;
}

Image ImageManager::Title() const
{
	return m_title;
}