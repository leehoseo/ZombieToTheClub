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
	if(_length < _radius1 + _radius2 )	//	 �߽� ������ �Ÿ��� �� �߽��� �պ��� ������(�浹äũ ������)
		return true;

	return false;
}
