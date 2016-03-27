#pragma once
class CrashCheck
{
private:
	CrashCheck();
public:
	
	static CrashCheck *Instance();
	~CrashCheck();

	bool Circle_Circle(float _radius1, float _radius2, float _length);
};

