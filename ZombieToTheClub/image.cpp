#include "image.h"

Image::Image()
{
	initialized = false;
	spriteData.width = 2;
	spriteData.height = 2;
	spriteData.x = 0.0;
	spriteData.y = 0.0;
	spriteData.scale = 1.0;
	spriteData.angle = 0.0;
	spriteData.rect.left = 0;
	spriteData.rect.top = 0;
	spriteData.rect.right = spriteData.width;
	spriteData.rect.bottom = spriteData.height;
	spriteData.texture = NULL;
	spriteData.flipHorizontal = false;
	spriteData.flipVertical = false;
	m_ptexture = NULL;
	visible = true;
	graphics = NULL;
	colorFilter = graphicsNS::WHITE;
}


Image::~Image()
{}

bool Image::initialize(Graphics* g, int x, int y, int frame , const char* file , ...)
{
	graphics = g;
	if (FAILED(graphics->loadTexture(file, TRANSCOLOR, spriteData.width, spriteData.height, this->m_ptexture))) // m_ptexture에 데이터 입력
		MessageBox(NULL, "Texture load FAIL", "ERROR Massage", NULL);

	spriteData.texture = this->m_ptexture;

	if (NULL == this->m_ptexture)
		return false;

	spriteData.rect.left = 0;
	// right edge + 1
	spriteData.rect.right = spriteData.width;
	spriteData.rect.top = 0;
	// bottom edge + 1
	spriteData.rect.bottom = spriteData.height;

	spriteData.x = x;
	spriteData.y = y;

	initialized = true;                                // successfully initialized
	return true;
}


void Image::draw(COLOR_ARGB color)
{
	if (!visible || graphics == NULL)
		return;
	spriteData.texture = this->m_ptexture;
	if (color == graphicsNS::FILTER)
		graphics->drawSprite(spriteData, colorFilter);
	else
		graphics->drawSprite(spriteData, color);
}

void Image::update()		// 애니메이션 관련 함수
{
}