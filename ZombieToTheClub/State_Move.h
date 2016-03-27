#pragma once
#include "State.h"
#include "ImageManager.h"
#include "Input.h"
#include "State_Stay.h"
#include "State_Attack.h"
#include "ImageManager.h"

template<typename T>
class State_Move	: public State<T>
{
private:
	State_Move() {};

public:
	
	static State_Move * Instance()
	{
		static State_Move instance;
		return &instance;
	}
	~State_Move() {};

	virtual void Update(T * _t)
	{
		if (!MoveCheck())// 안움직이면
		{
			if (_t->GetType() == eTYPE::PLAYER)
			{
				_t->SetCode(eSTATE::STAY);
				_t->ChangeImage(ImageManager::Instance()->Player_Stay());
				_t->ChangeState(State_Stay<T>::Instance());
			}
		}

		if (CInput::Instance()->KetPressedCheck(DIK_A))
		{
			if (_t->GetType() == eTYPE::PLAYER)
			{
				_t->SetCode(eSTATE::ATTACK);
				_t->ChangeImage(ImageManager::Instance()->Player_Attack());
				_t->ChangeState(State_Attack<T>::Instance());
			}
		}
		Move(_t);
	}
	void Move(T * _t)
	{
		_t->Move();
	}

	bool MoveCheck()
	{
		if (CInput::Instance()->KetPressedCheck(DIK_LEFT) || CInput::Instance()->KetPressedCheck(DIK_RIGHT)
			|| CInput::Instance()->KetPressedCheck(DIK_DOWN) || CInput::Instance()->KetPressedCheck(DIK_UP))
			return true;

		return false;
	}
	
};

