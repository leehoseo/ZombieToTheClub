#pragma once
#include "State.h"
#include "ImageManager.h"
#include "State_Stay.h"
#include "Time.h"

template<typename T>
class State_Attack	: public State<T>
{
private:
	State_Attack() {}
public:
	
	~State_Attack() {}

	static State_Attack * Instance()
	{
		static State_Attack instance;
		return &instance;
	}

	virtual void Update(T * _t)
	{
		Attack();
		if (!AttackCheck(_t))
		{
			if (Time::Instance()->Timer(10))
			{
				_t->SetCode(eSTATE::STAY);
				_t->ChangeImage(ImageManager::Instance()->Player_Stay());
				_t->ChangeState(State_Stay<T>::Instance());
			}
		}
	}

	void Attack() {}

	bool AttackCheck(T * _t)
	{
		if (_t->GetCurrentFrame() == _t->GetFrame())
		{
			return false;
		}
		return true;
	}
};

