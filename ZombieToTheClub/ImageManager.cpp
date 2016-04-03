#include "ImageManager.h"
#include "Resource.h"


ImageManager::ImageManager()
	: m_binitialize( false )
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
	m_title.initialize(g,800,240,112, 50 ,2, "Resource\\Title.png");

	m_attackCollisionBox.initialize(g, 0, 0, 0, 0, 0, "Resource\\Attack_CollisionBox.png");
	m_hitCollisionBox.initialize(g, 0, 0, 0, 0, 0, "Resource\\Hit_CollisionBox.png");
	m_traceCollisionBox.initialize(g, 0, 0, 0, 0, 0, "Resource\\Trace_CollisionBox.png");
	// Logo 이미지
	m_teamlogo.initialize(g, 0,0, 387 , 262 , 0,"Resource\\TeamLogo.png");


	// Main 이미지
	m_main.initialize(g,0,0, 0, 0, 0,"Resource\\main.png");
	m_ui_main_start.initialize(g,0,0 ,337, 300, 0,"Resource\\Start.png");
	m_ui_main_save.initialize(g,0,0, 337, 420, 0, "Resource\\Save.png");
	m_ui_main_option.initialize(g, 0,0,337, 540, 0, "Resource\\Option.png");
	m_ui_main_exit.initialize(g,0,0, 337, 660, 0, "Resource\\Exit.png");


	//Player
	m_player_move.initialize(g,128,128,0, 0, 10,  "Resource\\Player_Move.png");
	m_player_stay.initialize(g, 128, 128, 0, 0, 2,  "Resource\\Player_Stay.png");
	m_player_attack.initialize(g, 128, 128, 0, 0, 3,  "Resource\\Player_Attack.png");
	m_player_hit.initialize(g, 128, 128, 0, 0, 3, "Resource\\Player_Down.png");

	m_bz_stay.initialize(g, 128, 128, 0, 0, 6, "Resource\\bz1_stand.png");
	m_bz_move.initialize(g, 128, 128, 0, 0, 4, "Resource\\BZ_Move.png");
	m_bz_hit.initialize(g, 128, 128, 0, 0, 3, "Resource\\BZ_Hit.png");
	m_bz_attack.initialize(g, 128, 128, 0, 0, 4, "Resource\\BZ_Attack.png");
	m_binitialize = true;
}

bool ImageManager::IsInitialized()
{
	return m_binitialize;
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