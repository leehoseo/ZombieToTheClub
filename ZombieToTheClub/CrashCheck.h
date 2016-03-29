#pragma once
#include "graphics.h"
#include "image.h"
class CrashCheck
{
private:
	CrashCheck();
public:
	
	static CrashCheck *Instance();
	~CrashCheck();

	bool Circle_Circle(float _radius1, float _radius2, float _length);
	bool Rect_Rect(Image _image1, Image _image2);
};

