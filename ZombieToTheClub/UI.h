#pragma once
#include "image.h"

class UI
{
protected:
	Image m_image;

public:
	UI();
	~UI();

	void Initialize(Image _image) ;
	void Render() ;
	void Update() ;
	bool CollisionCheck();
};

