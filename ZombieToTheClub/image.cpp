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
	cols = 1;
	m_ptexture = NULL;
	startFrame = 0;
	endFrame = 0;
	currentFrame = 0;
	frameDelay = 1.0;               
	animTimer = 0.0;
	visible = true;                 
	loop = true;                    
	animComplete = false;
	graphics = NULL;                
	colorFilter = graphicsNS::WHITE;
}


Image::~Image()
{}

bool Image::initialize(Graphics* g, int width, int height, int ncols,
	const char* file)
{
		graphics = g;                          
		if (FAILED(graphics->loadTexture(file, TRANSCOLOR, width, height, this->m_ptexture))) // m_ptexture에 데이터 입력
			MessageBox(NULL , "Texture load FAIL" , "ERROR Massage" , NULL );
		
		spriteData.texture = this->m_ptexture;
		
		if (NULL == this->m_ptexture)
			return false;

		spriteData.width = width;
		
		spriteData.height = height;
		cols = ncols;
		if (cols == 0)
			cols = 1;                              

		spriteData.rect.left = (currentFrame % cols) * spriteData.width;
		// right edge + 1
		spriteData.rect.right = spriteData.rect.left + spriteData.width;
		spriteData.rect.top = (currentFrame / cols) * spriteData.height;
		// bottom edge + 1
		spriteData.rect.bottom = spriteData.rect.top + spriteData.height;

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

void Image::update(float frameTime)		// 애니메이션 관련 함수
{
	if (endFrame - startFrame > 0)        
	{
		animTimer += frameTime;           
		if (animTimer > frameDelay)
		{
			animTimer -= frameDelay;
			currentFrame++;
			if (currentFrame < startFrame || currentFrame > endFrame)
			{
				if (loop == true)            
					currentFrame = startFrame;
				else                        
				{
					currentFrame = endFrame;
					animComplete = true;    
				}
			}
			setRect();                      // 텍스쳐 재설정
		}
	}
}

void Image::setCurrentFrame(int c)		// 애니메이션 설정
{
	if (c >= 0)
	{
		currentFrame = c;
		animComplete = false;
		setRect();                      
	}
}

inline void Image::setRect()
{
	spriteData.rect.left = (currentFrame % cols) * spriteData.width;
	spriteData.rect.right = spriteData.rect.left + spriteData.width;
	spriteData.rect.top = (currentFrame / cols) * spriteData.height;
	spriteData.rect.bottom = spriteData.rect.top + spriteData.height;
}

