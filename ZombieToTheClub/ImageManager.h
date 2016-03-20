#pragma once
#include "graphics.h"
#include "image.h"

class ImageManager
{
private:
	Image m_zombie_1;
	Image m_ui_main_start;
	Image m_teamlogo;
	Image m_main;

	ImageManager();

	bool m_binitialize;

public:
	static ImageManager* Instance();

	virtual void initialize(Graphics* g);
	
	virtual ~ImageManager();

	bool IsInitialized();

	Image Zombie_1() const;
	Image UI_Main_Start() const;
	Image TeamLogo() const;
	Image Main() const;
};

