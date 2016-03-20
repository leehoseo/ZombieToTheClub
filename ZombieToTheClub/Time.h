#pragma once
#include <windows.h>
class Time
{
private:
	Time();

	DWORD m_time;

	bool m_btimerOn;

public:

	static Time* Instance();
	~Time();

	void SetTime();

	bool Timer(int _timer);
};

