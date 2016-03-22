#pragma once
#include "graphics.h"
#include "image.h"

class ImageManager
{
private:
	Image m_zombie_1;
	

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


	// Player
	Image m_player_move;
	Image m_player_stay;

	ImageManager();

	bool m_binitialize;

public:
	static ImageManager* Instance();

	virtual void initialize(Graphics* g);
	
	virtual ~ImageManager();

	bool IsInitialized();

	Image Zombie_1() const;
	Image TeamLogo() const;
	Image Main() const;

	Image Title() const;

	Image UI_Main_Start() const;
	Image UI_Main_Save() const;
	Image UI_Main_Option() const;
	Image UI_Main_Exit() const;

	//Player
	Image Player_Move() const;
	Image Player_Stay() const;
};

