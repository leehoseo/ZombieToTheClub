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
