#include "State_Stay.h"



#include "Player.h"

//template <typename T>
//State_Stay::State_Stay()
//{
//}
//
//template <typename T>
//State_Stay::~State_Stay()
//{
//}
//
//template <typename T>
//void State_Stay::Update(T * _t)
//{
//	if (MoveCheck())
//	{
//		_t->SetCode(eCODE::MOVE);
//		_t->ChangeImage(ImageManager::Instance()->Player_Move());
//		_t->ChangeState(new State_Move());
//	}
//
//	if (CInput::Instance()->KetPressedCheck(DIK_A))
//	{
//		_t->SetCode(eCODE::ATTACK);
//		_t->ChangeImage(ImageManager::Instance()->Player_Attack());
//		_t->ChangeState(new State_Attack());
//	}
//}
//
//template <typename T>
//bool State_Stay::MoveCheck()
//{
//	if (CInput::Instance()->KetPressedCheck(DIK_LEFT) || CInput::Instance()->KetPressedCheck(DIK_RIGHT)
//		|| CInput::Instance()->KetPressedCheck(DIK_DOWN) || CInput::Instance()->KetPressedCheck(DIK_UP))
//		return true;
//
//	return false;
//}
