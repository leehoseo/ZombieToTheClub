#include "Time.h"
#include <Windows.h>
#include <mmsystem.h>

Time::Time()
{
}

Time::~Time()
{
}

void Time::SetTime()
{
	m_time = timeGetTime() - m_startTime;
}

void Time::SetStartTime()
{
	m_startTime = timeGetTime();
}

int Time::GetTime() const
{
	return m_time;
}