#pragma once

#include <d3d9.h>
#include <d3dx9.h>

#define COLOR_ARGB DWORD
#define SETCOLOR_ARGB(a,r,g,b) \
    ((COLOR_ARGB)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))


namespace graphicsNS
{
	// Some common colors
	// ARGB numbers range from 0 through 255
	// A = Alpha channel (transparency where 255 is opaque)
	// R = Red, G = Green, B = Blue
	const COLOR_ARGB ORANGE = D3DCOLOR_ARGB(255, 255, 165, 0);
	const COLOR_ARGB BROWN = D3DCOLOR_ARGB(255, 139, 69, 19);
	const COLOR_ARGB LTGRAY = D3DCOLOR_ARGB(255, 192, 192, 192);
	const COLOR_ARGB GRAY = D3DCOLOR_ARGB(255, 128, 128, 128);
	const COLOR_ARGB OLIVE = D3DCOLOR_ARGB(255, 128, 128, 0);
	const COLOR_ARGB PURPLE = D3DCOLOR_ARGB(255, 128, 0, 128);
	const COLOR_ARGB MAROON = D3DCOLOR_ARGB(255, 128, 0, 0);
	const COLOR_ARGB TEAL = D3DCOLOR_ARGB(255, 0, 128, 128);
	const COLOR_ARGB GREEN = D3DCOLOR_ARGB(255, 0, 128, 0);
	const COLOR_ARGB NAVY = D3DCOLOR_ARGB(255, 0, 0, 128);
	const COLOR_ARGB WHITE = D3DCOLOR_ARGB(255, 255, 255, 255);
	const COLOR_ARGB YELLOW = D3DCOLOR_ARGB(255, 255, 255, 0);
	const COLOR_ARGB MAGENTA = D3DCOLOR_ARGB(255, 255, 0, 255);
	const COLOR_ARGB RED = D3DCOLOR_ARGB(255, 255, 0, 0);
	const COLOR_ARGB CYAN = D3DCOLOR_ARGB(255, 0, 255, 255);
	const COLOR_ARGB LIME = D3DCOLOR_ARGB(255, 0, 255, 0);
	const COLOR_ARGB BLUE = D3DCOLOR_ARGB(255, 0, 0, 255);
	const COLOR_ARGB BLACK = D3DCOLOR_ARGB(255, 0, 0, 0);
	const COLOR_ARGB FILTER = D3DCOLOR_ARGB(0, 0, 0, 0);  // use to specify drawing with colorFilter
	const COLOR_ARGB ALPHA25 = D3DCOLOR_ARGB(64, 255, 255, 255);  // AND with color to get 25% alpha
	const COLOR_ARGB ALPHA50 = D3DCOLOR_ARGB(128, 255, 255, 255);  // AND with color to get 50% alpha
	const COLOR_ARGB BACK_COLOR = BLACK;                         // background color of game

	enum DISPLAY_MODE { TOGGLE, FULLSCREEN, WINDOW };
}

// SpriteData: The properties required by Graphics::drawSprite to draw a sprite
struct SpriteData
{
	int					 width;      // width of sprite in pixels
	int					 height;     // height of sprite in pixels
	float				 x;          // screen location (top left corner of sprite)
	float				 y;
	float				 scale;      // <1 smaller, >1 bigger
	float				 angle;      // rotation angle in radians
	RECT				 rect;       // used to select an image from a larger texture
	LPDIRECT3DTEXTURE9	 texture;    // pointer to texture
	bool				 flipHorizontal; // true to flip sprite horizontally (mirror)
	bool				 flipVertical;   // true to flip sprite vertically
};

class Graphics
{
private:
	// DirectX pointers and stuff
	LPDIRECT3D9				direct3d;
	LPDIRECT3DDEVICE9		device3d;
	LPD3DXSPRITE			sprite;
	D3DPRESENT_PARAMETERS	d3dpp;
	D3DDISPLAYMODE			pMode;

	// other variables
	HRESULT     result;         // standard Windows return codes
	HWND        hwnd;
	bool        fullscreen;
	int         width;
	int         height;
	COLOR_ARGB	backColor;      // background color ARGB

								// (For internal engine use only. No user serviceable parts inside.)
								// Initialize D3D presentation parameters
	void    initD3Dpp();

public:
	// Constructor
	Graphics();

	// Destructor
	virtual ~Graphics();

	// Releases direct3d and device3d.
	void    releaseAll();

	void    initialize(HWND hw, int width, int height, bool fullscreen);

	HRESULT loadTexture(const char * filename, COLOR_ARGB transcolor, int &width, int &height, LPDIRECT3DTEXTURE9 &texture);

	// Display the offscreen backbuffer to the screen.
	HRESULT showBackbuffer();

	
	void    drawSprite(const SpriteData &spriteData,COLOR_ARGB color = graphicsNS::WHITE);

	HRESULT beginScene();
	HRESULT endScene();
	HRESULT reset();
};