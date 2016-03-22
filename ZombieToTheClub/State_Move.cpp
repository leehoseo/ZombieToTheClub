#include "State_Move.h"
#include "ImageManager.h"
#include "Input.h"
#include "State_Stay.h"
#include "Player.h"

State_Move::State_Move()
{
}


State_Move::~State_Move()
{
}

void State_Move::Render()
{
}

void State_Move::Update()
{
	if (!MoveCheck())// 안움직이면
	{
		Player::Instance()->ChangeImage(ImageManager::Instance()->Player_Stay());
		Player::Instance()->ChangeState(new State_Stay());
	}
	Move();
}

void State_Move::Move()
{
	Player::Instance()->Move();
}

bool State_Move::MoveCheck()
{
	if (CInput::Instance()->KetPressedCheck(DIK_LEFT) || CInput::Instance()->KetPressedCheck(DIK_RIGHT)
		|| CInput::Instance()->KetPressedCheck(DIK_DOWN) || CInput::Instance()->KetPressedCheck(DIK_UP))
		return true;

	return false;
}
