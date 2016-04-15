#pragma once
#include "ImageManager.h"

class LeftHand
{
private:
	Image m_image;
	int m_code;
public:
	LeftHand();
	~LeftHand();

	void Initialize();
	void Update();
	void Render();
	void ChangeAni(Image _image);
	bool AniEnd();
};

