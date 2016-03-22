#include "image.h"
#include "Time.h"

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
	m_width = 0;
	m_height = 0;
	m_frame = 0;
	m_frameDeley = 0;
	m_currentFrame = 0;
	m_endFrame = 0;
	colorFilter = graphicsNS::WHITE;
}


Image::~Image()
{}

// spriteData.width, spriteData.height : 텍스쳐 전체 크기
// m_width , m_heigth : 설정한 텍스쳐 크기(애니메이션 사용에 필요)
bool Image::initialize(Graphics* _g , int _width , int _height, int _x, int _y, int _frame , int _frameDeley , const char* _file)
{
	graphics = _g;
	if (FAILED(graphics->loadTexture(_file, TRANSCOLOR, spriteData.width, spriteData.height, this->m_ptexture))) // m_ptexture에 데이터 입력
		MessageBox(NULL, "Texture load FAIL", "ERROR Massage", NULL);

	spriteData.texture = this->m_ptexture;

	if (NULL == this->m_ptexture)
		return false;
	
	spriteData.rect.left = 0;
	// right edge + 1
	spriteData.rect.right = spriteData.width;

	if (_width != 0)
		spriteData.rect.right = _width;

	spriteData.rect.top = 0;
	// bottom edge + 1
	spriteData.rect.bottom = spriteData.height;

	spriteData.x = _x;
	spriteData.y = _y;

	m_width = _width;
	m_height = _height;
	m_frame = _frame;
	m_endFrame = _frame;
	m_frameDeley = _frameDeley;

	
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
	if (m_endFrame != 0)// 애니메이션이 있으면
	{
		static DWORD deleyCheck = Time::Instance()->GetTime() + m_frameDeley;

		if (Time::Instance()->GetTime() > deleyCheck)	// 시간이 지나면
		{
			spriteData.rect.left = (spriteData.width / m_frame) * m_currentFrame;	// 설정한 개인 프레임 width 값 x 현재 frame 번호
			spriteData.rect.right = (spriteData.width / m_frame) * (m_currentFrame + 1);

			// 애니메이션 종류가 나뉘면 따로 설정하자
			spriteData.rect.top = 0;
			spriteData.rect.bottom = spriteData.height;

			deleyCheck += m_frameDeley;
		}

		++m_currentFrame;
		if (m_currentFrame == m_endFrame)
			m_currentFrame = 0;
	}
}