#pragma once
#include "State.h"
#include "image.h"
#include "State_Move.h"
#include "State_Attack.h"
#include "Input.h"
#include "ImageManager.h"

template <typename T>
class State_Stay : public State<T>
{
private:
	State_Stay() {};

public:
	~State_Stay() {};
	
	static State_Stay * Instance()
	{
		static State_Stay instance;
		return &instance;
	}

	virtual void Update(T * _t)
	{
		if (MoveCheck())
		{
			_t->SetCode(eSTATE::MOVE);
			_t->ChangeImage(ImageManager::Instance()->Player_Move());
			_t->ChangeState(State_Move<T>::Instance());
		}

		if (CInput::Instance()->KetPressedCheck(DIK_A))
		{
			_t->SetCode(eSTATE::ATTACK);
			_t->ChangeImage(ImageManager::Instance()->Player_Attack());
			_t->ChangeState(State_Attack<T>::Instance());
		}
	}

	bool MoveCheck()
	{
		if (CInput::Instance()->KetPressedCheck(DIK_LEFT) || CInput::Instance()->KetPressedCheck(DIK_RIGHT)
			|| CInput::Instance()->KetPressedCheck(DIK_DOWN) || CInput::Instance()->KetPressedCheck(DIK_UP))
			return true;

		return false;
	}
};

