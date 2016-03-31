#pragma once
#include <d3dx9core.h>
class Text
{
private:
	Text();
	IDirect3DDevice9* m_pDevice;
	ID3DXFont*  m_pFont;
	int         m_nMax_X;
	int         m_nMax_Y;

public:
	~Text();
	static Text* Instaance();

	void Initialize(LPDIRECT3DDEVICE9 _devive);
	void Print(LPCSTR _string, int _x , int _y, D3DXCOLOR ARGB = 0xFFFFFFFF);
};
