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

	//Player
	m_player_move.initialize(g, 128, 128, 0, 0, 10, "../ZombieToTheClub\\Resource\\Player_Move.png");
	m_player_stay.initialize(g, 128, 128, 0, 0, 2, "../ZombieToTheClub\\Resource\\Player_Stay.png");
	m_player_attack.initialize(g, 128, 128, 0, 0, 3, "../ZombieToTheClub\\Resource\\Player_Attack.png");
	m_player_hit.initialize(g, 128, 128, 0, 0, 3, "../ZombieToTheClub\\Resource\\Player_Down.png");

	m_bz_stay.initialize(g, 128, 128, 0, 0, 6, "../ZombieToTheClub\\Resource\\bz1_stand.png");
	m_bz_move.initialize(g, 128, 128, 0, 0, 4, "../ZombieToTheClub\\Resource\\BZ_Move.png");
	m_bz_hit.initialize(g, 128, 128, 0, 0, 3, "../ZombieToTheClub\\Resource\\BZ_Hit.png");
	m_bz_attack.initialize(g, 128, 128, 0, 0, 4, "../ZombieToTheClub\\Resource\\BZ_Attack.png");

	m_scone_score.initialize(g, 0, 0, 0, 0, 0, "../ZombieToTheClub\\Resource\\Score.png");

	m_gold.initialize(g, 0, 0, 0, 0, 0, "../ZombieToTheClub\\Resource\\Gold.png");
}

Image ImageManager::BZ_Stay() const
{
	return m_bz_stay;
}

Image ImageManager::BZ_Move() const
{
	return m_bz_move;
}

Image ImageManager::BZ_Hit() const
{
	return m_bz_hit;
}

Image ImageManager::BZ_Attack() const
{
	return m_bz_attack;
}

Image ImageManager::Scone_Score() const
{
	return m_scone_score;
}

Image ImageManager::Gold() const
{
	return m_gold;
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