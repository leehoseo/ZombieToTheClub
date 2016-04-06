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
	spriteData.pixelX = 0;
	spriteData.pixelY = 0;
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
	colorFilter = graphicsNS::WHITE;

	m_time.SetStartTime();
}


Image::~Image()
{}

// spriteData.width, spriteData.height : �ؽ��� ��ü ũ��
// m_width , m_heigth : ������ �ؽ��� ũ��(�ִϸ��̼� ��뿡 �ʿ�)
bool Image::initialize(Graphics* _g , int _width , int _height, int _x, int _y, int _frame , const char* _file)
{
	graphics = _g;
	if (FAILED(graphics->loadTexture(_file, TRANSCOLOR, spriteData.width, spriteData.height, this->m_ptexture))) // m_ptexture�� ������ �Է�
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
	spriteData.pixelX = m_width;
	spriteData.pixelY = m_height;
	
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

void Image::update(int _deley)		// �ִϸ��̼� ���� �Լ�
{ 
	if (m_frame != 0)// �ִϸ��̼��� ������
	{
		m_time.SetTime();

		if (m_time.GetTime() > _deley)	// �ð��� ������
		{
			if (m_currentFrame == m_frame)
				m_currentFrame = 0;

			spriteData.rect.left = (spriteData.width / m_frame) * m_currentFrame;	// ������ ���� ������ width �� x ���� frame ��ȣ
			spriteData.rect.right = (spriteData.width / m_frame) * (m_currentFrame + 1);

			// �ִϸ��̼� ������ ������ ���� ��������
			spriteData.rect.top = 0;
			spriteData.rect.bottom = spriteData.height;

			m_time.SetStartTime();
			++m_currentFrame;
		}
	}
}