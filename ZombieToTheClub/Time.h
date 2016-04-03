#pragma once

class Time
{
private:
	int m_time;
	int m_startTime;
	int m_gameTime;

public:
	Time();
	~Time();

	void SetTime();
	void SetStartTime();
	int GetTime() const;
};

