#pragma once

template<typename T>
class State
{
public:
	State() {}
	~State() {}

	virtual void Update(T * _t) = 0;
};

