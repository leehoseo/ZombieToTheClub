#pragma once
#define WIN32_LEAN_AND_MEAN

#include "Resource.h"
#include "graphics.h"
#include "Time.h"

class Image		// 부모클래스로 이후 다양한 오브젝트들이 생기면 상속하여 사용
{
	// Image properties
protected:
	Graphics *graphics;     // pointer to graphics
	LPDIRECT3DTEXTURE9 m_ptexture; // pointer to texture manager
								   // spriteData contains the data required to draw the image by Graphics::drawSprite()
	SpriteData spriteData;  // SpriteData is defined in "graphics.h"
	COLOR_ARGB colorFilter; // applied as a color filter (use WHITE for no change)
	int m_width;
	int m_height;
	int m_frame;
	int m_frameDeley;
	int m_currentFrame;

	int m_startTime;
	int m_currentTime;
	HRESULT hr;             // standard return type
	bool    visible;        // true when visible
	bool    initialized;    // true when successfully initialized
	bool    animComplete;   // true when loop is false and endFrame has finished displaying

	Time m_time;

public:
	// Constructor
	Image();
	// Destructor
	virtual ~Image();

	////////////////////////////////////////
	//           Get functions            //
	////////////////////////////////////////

	// Return reference to SpriteData structure.
	const virtual SpriteData& getSpriteInfo() { return spriteData; }

	// Return visible parameter.
	virtual bool  getVisible() { return visible; }

	// Return X position.
	virtual float getX() const { return spriteData.x; }

	// Return Y position.
	virtual float getY() const { return spriteData.y; }

	// Return scale factor.
	virtual float getScale() const { return spriteData.scale; }

	virtual int GetCurrentFrame() const { return m_currentFrame; }
	virtual int GetFrame() const { return m_frame; }

	virtual int   getWidth() { return spriteData.width; }

	// Return height.
	virtual int   getHeight() { return spriteData.height; }

	virtual int	  getPixelX() { return spriteData.pixelX; }

	virtual int	  getPixelY() { return spriteData.pixelY; }
	// Return center X.
	virtual float getCenterX() const { return spriteData.x + spriteData.pixelX / 2 * getScale(); }

	// Return center Y.
	virtual float getCenterY() const { return spriteData.y + spriteData.pixelY / 2 * getScale(); }

	virtual float getRadius() const { return _hypot(spriteData.pixelX / 2, spriteData.pixelY / 2);  }
	// Return rotation angle in degrees.
	virtual float getDegrees() { return spriteData.angle*(180.0f / (float)PI); }

	// Return rotation angle in radians.
	virtual float getRadians() { return spriteData.angle; }

	// Return RECT structure of Image.
	virtual RECT  getSpriteDataRect() { return spriteData.rect; }

	// Return state of animation complete.
	virtual bool  getAnimationComplete() { return animComplete; }

	// Return colorFilter.
	virtual COLOR_ARGB getColorFilter() { return colorFilter; }

	virtual void setX(float newX) { spriteData.x = newX; }

	// Set Y location.
	virtual void setY(float newY) { spriteData.y = newY; }

	// Set scale.
	virtual void setScale(float s) { spriteData.scale = s; }

	virtual void setDegrees(float deg) { spriteData.angle = deg*((float)PI / 180.0f); }

	// Set rotation angle in radians.
	// 0 radians is up. Angles progress clockwise.
	virtual void setRadians(float rad) { spriteData.angle = rad; }

	// Set visible.
	virtual void setVisible(bool v) { visible = v; }


	// Set spriteData.rect to r.
	virtual void setSpriteDataRect(RECT r) { spriteData.rect = r; }

	// Set animation complete Boolean.
	virtual void setAnimationComplete(bool a) { animComplete = a; };

	// Set color filter. (use WHITE for no change)
	virtual void setColorFilter(COLOR_ARGB color) { colorFilter = color; }


	virtual bool Image::initialize(Graphics* _g, int _width, int _height, int _x, int _y,  int _frame , const char* _file);

	virtual bool GetHorizontal() const { return spriteData.flipHorizontal; }
	virtual void flipHorizontal(bool flip) { spriteData.flipHorizontal = flip; }

	// 상하 반전
	virtual void flipVertical(bool flip) { spriteData.flipVertical = flip; }

	virtual void draw(COLOR_ARGB color = graphicsNS::WHITE);

	virtual void update(int _deley);
};