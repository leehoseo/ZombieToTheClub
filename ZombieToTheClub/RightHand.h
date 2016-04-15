#pragma once
#include "ImageManager.h"
class RightHand
{
private:
	Image m_image;
	int m_code;
public:
	RightHand();
	~RightHand();

	void Initialize();
	void Update();
	void Render();
	void ChangeAni(Image _image);
	bool AniEnd();
};

