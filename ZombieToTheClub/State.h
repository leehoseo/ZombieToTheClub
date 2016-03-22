#pragma once
class State
{
public:
	State();
	~State();

	virtual void Render() = 0;
	virtual void Update() = 0;
};

