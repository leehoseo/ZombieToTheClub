#pragma once
#define WIN32_LEAN_AND_MEAN

#include "Resource.h"
#include "graphics.h"

class Image		// �θ�Ŭ������ ���� �پ��� ������Ʈ���� ����� ����Ͽ� ���
{
	// Image properties
protected:
	Graphics *graphics;     // pointer to graphics
	LPDIRECT3DTEXTURE9 m_ptexture; // pointer to texture manager
									// spriteData contains the data required to draw the image by Graphics::drawSprite()
	SpriteData spriteData;  // SpriteData is defined in "graphics.h"
	COLOR_ARGB colorFilter; // applied as a color filter (use WHITE for no change)
	int     cols;           // number of cols (1 to n) in multi-frame sprite
	int     startFrame;     // first frame of current animation
	int     endFrame;       // end frame of current animation
	int     currentFrame;   // current frame of animation
	float   frameDelay;     // how long between frames of animation
	float   animTimer;      // animation timer
	HRESULT hr;             // standard return type
	bool    loop;           // true to loop frames
	bool    visible;        // true when visible
	bool    initialized;    // true when successfully initialized
	bool    animComplete;   // true when loop is false and endFrame has finished displaying

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
	virtual float getX() { return spriteData.x; }

	// Return Y position.
	virtual float getY() { return spriteData.y; }

	// Return scale factor.
	virtual float getScale() { return spriteData.scale; }

	// Return width.
	virtual int   getWidth() { return spriteData.width; }

	// Return height.
	virtual int   getHeight() { return spriteData.height; }

	// Return center X.
	virtual float getCenterX() { return spriteData.x + spriteData.width / 2 * getScale(); }

	// Return center Y.
	virtual float getCenterY() { return spriteData.y + spriteData.height / 2 * getScale(); }

	// Return rotation angle in degrees.
	virtual float getDegrees() { return spriteData.angle*(180.0f / (float)PI); }

	// Return rotation angle in radians.
	virtual float getRadians() { return spriteData.angle; }

	// Return delay between frames of animation.
	virtual float getFrameDelay() { return frameDelay; }

	// Return number of starting frame.
	virtual int   getStartFrame() { return startFrame; }

	// Return number of ending frame.
	virtual int   getEndFrame() { return endFrame; }

	// Return number of current frame.
	virtual int   getCurrentFrame() { return currentFrame; }

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

	// Set rotation angle in degrees.
	// 0 degrees is up. Angles progress clockwise.
	virtual void setDegrees(float deg) { spriteData.angle = deg*((float)PI / 180.0f); }

	// Set rotation angle in radians.
	// 0 radians is up. Angles progress clockwise.
	virtual void setRadians(float rad) { spriteData.angle = rad; }

	// Set visible.
	virtual void setVisible(bool v) { visible = v; }

	// Set delay between frames of animation.
	virtual void setFrameDelay(float d) { frameDelay = d; }

	// Set starting and ending frames of animation.
	virtual void setFrames(int s, int e) { startFrame = s; endFrame = e; }

	// Set current frame of animation.
	virtual void setCurrentFrame(int c);

	// Set spriteData.rect to draw currentFrame
	virtual void setRect();

	// Set spriteData.rect to r.
	virtual void setSpriteDataRect(RECT r) { spriteData.rect = r; }

	// Set animation loop. lp = true to loop.
	virtual void setLoop(bool lp) { loop = lp; }

	// Set animation complete Boolean.
	virtual void setAnimationComplete(bool a) { animComplete = a; };

	// Set color filter. (use WHITE for no change)
	virtual void setColorFilter(COLOR_ARGB color) { colorFilter = color; }



	virtual bool Image::initialize(Graphics* g, int width, int height,
		int ncols, const char* file);

	// �¿� ����
	virtual void flipHorizontal(bool flip) { spriteData.flipHorizontal = flip; }

	// ���� ����
	virtual void flipVertical(bool flip) { spriteData.flipVertical = flip; }

	
	virtual void draw(COLOR_ARGB color = graphicsNS::WHITE);

	virtual void update(float frameTime);
};
