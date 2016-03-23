#include "graphics.h"
#include "Resource.h"

Graphics::Graphics()
{
	direct3d = NULL;
	device3d = NULL;
	sprite = NULL;
	fullscreen = false;
	width = GAME_WIDTH;    // width & height are replaced in initialize()
	height = GAME_HEIGHT;
	backColor = graphicsNS::BACK_COLOR;
}

//=============================================================================
// Destructor
//=============================================================================
Graphics::~Graphics()
{
	releaseAll();
}

//=============================================================================
// Release all
//=============================================================================
void Graphics::releaseAll()
{
	SAFE_RELEASE(sprite);
	SAFE_RELEASE(device3d);
	SAFE_RELEASE(direct3d);
}

//=============================================================================
// Initialize DirectX graphics
// throws GameError on error
//=============================================================================
void Graphics::initialize(HWND hw, int w, int h, bool full)
{
	hwnd = hw;
	width = w;
	height = h;
	fullscreen = full;
	
	//initialize Direct3D
	direct3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (direct3d == NULL)
	{
		MESSAGEBOX("directx Create Error");
		PostQuitMessage(0);
		
	}
		
	initD3Dpp();        // init D3D presentation parameters

	// determine if graphics card supports harware texturing and lighting and vertex shaders
	D3DCAPS9 caps;
	DWORD behavior = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	result = direct3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
	

	if (FAILED(result))
		PostQuitMessage(0);


	result = direct3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		behavior,
		&d3dpp,
		&device3d);

	if (FAILED(result))
		PostQuitMessage(0);

	result = D3DXCreateSprite(device3d, &sprite);

	if (FAILED(result))
		PostQuitMessage(0);

}

// 백버퍼 설정
void Graphics::initD3Dpp()
{
	ZeroMemory(&d3dpp, sizeof(d3dpp));              // fill the structure with 0
													// fill in the parameters we need
	d3dpp.BackBufferWidth = width;
	d3dpp.BackBufferHeight = height;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;   // use desktop setting
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hwnd;
	d3dpp.Windowed = (!fullscreen);
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

}

// HRESULT 변수 : SUCCEEDED 같은 HRESULT 형 함수를 사용해서 예외처리를 하기위해씀
// bool 함수와 차이점 : bool함수와는 다르게 반드시 값을 리턴 받지않아도됨
HRESULT Graphics::loadTexture(const char *filename, COLOR_ARGB transcolor,
	int &width, int &height, LPDIRECT3DTEXTURE9 &texture)
{
	// The struct for reading file info
	D3DXIMAGE_INFO info;
	result = E_FAIL;

	if (filename == NULL)
	{
		texture = NULL;
		MessageBoxA(NULL , "Non Texture", NULL , NULL);
	}

	// Get width and height from file
	result = D3DXGetImageInfoFromFile(filename, &info);
	if (result != D3D_OK)
		return result;
	width = info.Width;
	height = info.Height;

	// Create the new texture by loading from file
	result = D3DXCreateTextureFromFileEx(
		device3d,           //3D device
		filename,           //image filename
		info.Width,         //texture width
		info.Height,        //texture height
		1,                  //mip-map levels (1 for no chain)
		0,                  //usage
		D3DFMT_UNKNOWN,     //surface format (default)
		D3DPOOL_DEFAULT,    //memory class for the texture
		D3DX_DEFAULT,       //image filter
		D3DX_DEFAULT,       //mip filter
		transcolor,         //color key for transparency
		&info,              //bitmap file info (from loaded file)
		NULL,               //color palette
		&texture);         //destination texture

	return result;
}

//=============================================================================
// Display the backbuffer
//=============================================================================
HRESULT Graphics::showBackbuffer()
{
	result = E_FAIL;    // default to fail, replace on success
						// Display backbuffer to screen
	result = device3d->Present(NULL, NULL, NULL, NULL);		// 백버퍼를 표면으로 올려주는 함수
	return result;
}
void Graphics::drawSprite(const SpriteData &spriteData, COLOR_ARGB color)
{
	if (spriteData.texture == NULL)      // if no texture
		return;

	// Find center of sprite
	D3DXVECTOR2 spriteCenter = D3DXVECTOR2((float)(spriteData.width / 2 * spriteData.scale),
		(float)(spriteData.height / 2 * spriteData.scale));
	// Screen position of the sprite
	D3DXVECTOR2 translate = D3DXVECTOR2((float)spriteData.x, (float)spriteData.y);
	// Scaling X,Y
	D3DXVECTOR2 scaling(spriteData.scale, spriteData.scale);
	if (spriteData.flipHorizontal)  // if flip horizontal
	{
		scaling.x *= -1;            // negative X scale to flip
									// Get center of flipped image.
		//spriteCenter.x -= (float)(spriteData.width*spriteData.scale);
		// Flip occurs around left edge, translate right to put
		// Flipped image in same location as original.
		translate.x = spriteData.x + spriteData.pixelX;
	}
	if (spriteData.flipVertical)    // if flip vertical
	{
		scaling.y *= -1;            // negative Y scale to flip
									// Get center of flipped image
		spriteCenter.y -= (float)(spriteData.height*spriteData.scale);
		// Flip occurs around top edge, translate down to put
		// Flipped image in same location as original.
		translate.y += (float)(spriteData.height*spriteData.scale);
	}
	// Create a matrix to rotate, scale and position our sprite
	D3DXMATRIX matrix;
	D3DXMatrixTransformation2D(
		&matrix,                // the matrix
		NULL,                   // keep origin at top left when scaling
		0.0f,                   // no scaling rotation
		&scaling,               // scale amount
		&spriteCenter,          // rotation center
		(float)(spriteData.angle),  // rotation angle
		&translate);            // X,Y location

								// Tell the sprite about the matrix "Hello Neo"
	sprite->SetTransform(&matrix);

	// Draw the sprite
	sprite->Draw(spriteData.texture, &spriteData.rect, NULL, NULL, color);
}

HRESULT Graphics::beginScene()
{
	result = E_FAIL;
	if (device3d == NULL)
		return result;
	// clear backbuffer to backColor
	device3d->Clear(0, NULL, D3DCLEAR_TARGET, backColor, 1.0F, 0);
	device3d->BeginScene();          // begin scene for drawing

	result = sprite->Begin(D3DXSPRITE_ALPHABLEND);

	return result;
}


HRESULT Graphics::endScene()
{
	result = E_FAIL;

	sprite->End();

	if (device3d)
		result = device3d->EndScene();
	return result;
}

HRESULT Graphics::reset()
{
	result = E_FAIL;    // default to fail, replace on success
	initD3Dpp();                        // init D3D presentation parameters
	sprite->OnLostDevice();
	result = device3d->Reset(&d3dpp);   // attempt to reset graphics device

	sprite->OnResetDevice();
	return result;
}