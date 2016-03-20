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
	m_zombie_1.initialize(g, 0, 0,"Resource\\Zombie.png");

	// Logo 이미지
	m_teamlogo.initialize(g, 387 , 262 , "Resource\\TeamLogo.png");


	// Main 이미지
	m_main.initialize(g, 0, 0,  "Resource\\main.png");
	m_ui_main_start.initialize(g, 337, 300,  "Resource\\Start.png");
	m_ui_main_save.initialize(g, 337, 420,  "Resource\\Save.png");
	m_ui_main_option.initialize(g, 337, 540,  "Resource\\Option.png");
	m_ui_main_exit.initialize(g, 337, 660,  "Resource\\Exit.png");

	m_title[0].initialize(g, 112, 50,  "Resource\\Title1.png");
	m_title[1].initialize(g, 112, 100,  "Resource\\Title2.png");
	m_binitialize = true;
}

bool ImageManager::IsInitialized()
{
	return m_binitialize;
}

Image ImageManager::Zombie_1() const
{
	return m_zombie_1;
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

Image * ImageManager::Title()
{
	return m_title;
}