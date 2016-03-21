#include "Time.h"
#include <stdio.h>


Time::Time()
	: m_btimerOn(false)
{
}


Time * Time::Instance()
{
	static Time instance;

	return &instance;
}

Time::~Time()
{
}

void Time::SetTime()
{
	m_time = timeGetTime();
}

bool Time::Timer(int _timer)
{
	static int timer = 0;

	if (m_btimerOn == false)
	{
		timer = timeGetTime() + _timer;
		m_btimerOn = true;
	}

	if (m_time > timer)
	{
		m_btimerOn = false;
		return true;
	}
	return false;
}

DWORD Time::GetTime() const
{
	return m_time;
}
