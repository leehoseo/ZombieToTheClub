#include "CrashCheck.h"
#include <math.h>


CrashCheck::CrashCheck()
{
}


CrashCheck * CrashCheck::Instance()
{
	static CrashCheck instance;
	return &instance;
}

CrashCheck::~CrashCheck()
{
}

bool CrashCheck::Circle_Circle(float _radius1, float _radius2, float _length)
{
	if(_length < _radius1 + _radius2 )	//	 중심 사이의 거리가 두 중심의 합보다 작을때(충돌채크 됐을때)
		return true;

	return false;
}

bool CrashCheck::Rect_Rect(Image _image1, Image _image2)
{
	// 수평 충돌체크
	if((_image1.getX() + _image1.getWidth()) > _image2.getX() && _image1.getX() < (_image2.getX() + _image2.getWidth())
	&& (_image1.getY() + _image1.getHeight()) > _image2.getY() && _image1.getY() < (_image2.getY() + _image2.getHeight()))
		return true;

	return false;
}
