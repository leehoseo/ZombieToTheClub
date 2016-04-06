#include "Text.h"
#include "Resource.h"
#include <string>

Text::Text()
{
}


Text::~Text()
{
}

Text * Text::Instaance()
{
	static Text instance;
	return &instance;
}

void Text::Initialize(LPDIRECT3DDEVICE9 _devive)
{
	m_pDevice = _devive;

	D3DXFONT_DESC DXFont_DESC;
	ZeroMemory(&DXFont_DESC, sizeof(D3DXFONT_DESC));
	DXFont_DESC.Height = 15;                            // 전체 글자 높이
	DXFont_DESC.Width = 15;                             // 전체 글자 넓이
	DXFont_DESC.Weight = FW_NORMAL;                     // 긁자 굵기 ( FW_BOLD 하면 굵음 )
	DXFont_DESC.MipLevels = D3DX_DEFAULT;
	DXFont_DESC.Italic = false;                         // 이텔릭
	DXFont_DESC.CharSet = DEFAULT_CHARSET;
	DXFont_DESC.OutputPrecision = OUT_DEFAULT_PRECIS;
	DXFont_DESC.Quality = DEFAULT_QUALITY;
	DXFont_DESC.PitchAndFamily = DEFAULT_PITCH;
	strcpy_s(DXFont_DESC.FaceName, "궁서체");              // 글씨체
	m_nMax_X = GAME_WIDTH;                               // 윈도우 최대 X
	m_nMax_Y = GAME_HEIGHT;                                // 윈도우 최대 Y
	D3DXCreateFontIndirect(m_pDevice, &DXFont_DESC, &m_pFont);

	D3DXCreateFont(m_pDevice,          // D3D device
		DXFont_DESC.Height,            // Height
		DXFont_DESC.Width,            // Width
		DXFont_DESC.Weight,          // Weight
		DXFont_DESC.MipLevels,            // MipLevels, 0 = autogen mipmaps
		FALSE,          // Italic
		DEFAULT_CHARSET,    // CharSet
		OUT_DEFAULT_PRECIS,    // OutputPrecision
		DEFAULT_QUALITY,    // Quality
		DEFAULT_PITCH | FF_DONTCARE, // PitchAndFamily
		DXFont_DESC.FaceName,        // pFaceName
		&m_pFont);        // ppFont

}

void Text::Print(LPCSTR _string, int _x, int _y, D3DXCOLOR ARGB)
{
	RECT rect = { _x, _y, m_nMax_X, m_nMax_Y };

	m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, ARGB, 1.0f, 0);
	m_pDevice->BeginScene();

	m_pFont->DrawText(0,
		_string,
		-1, // size of string or -1 indicates null terminating string
		&rect,            // rectangle text is to be formatted to in windows coords
		DT_TOP | DT_LEFT, // draw in the top left corner of the viewport
		ARGB);      // black text


	m_pFont->DrawText(0, _string, -1, &rect, DT_TOP | DT_LEFT, ARGB);

	m_pDevice->EndScene();
	return;
}