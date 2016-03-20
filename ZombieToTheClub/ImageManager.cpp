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
	m_zombie_1.initialize(g, 0, 0, 0, 0,0,"Resource\\Zombie1.png");
	m_ui_main_start.initialize(g, 0, 0, 480, 400 , 0 ,"Resource\\GameStart.jpg");
	m_teamlogo.initialize(g, 0, 0, 387 , 262 , 0,"Resource\\TeamLogo.png");
	m_main.initialize(g, 0, 0, 0, 0, 0, "Resource\\main.png");
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

Image ImageManager::UI_Main_Start() const
{
	return m_ui_main_start;
}

Image ImageManager::TeamLogo() const 
{
	return m_teamlogo;
}

Image ImageManager::Main() const
{
	return m_main;
}
