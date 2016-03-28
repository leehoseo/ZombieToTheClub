#include "State_Stay.h"
#include "ImageManager.h"
#include "Input.h"
#include "State_Move.h"
#include "State_Attack.h"
#include "Player.h"

State_Stay::State_Stay()
{
}


State_Stay::~State_Stay()
{
}


void State_Stay::Update()
{
	if (MoveCheck())
	{
		Player::Instance()->SetCode(eSTATE::MOVE);
		Player::Instance()->ChangeImage(ImageManager::Instance()->Player_Move());
		Player::Instance()->ChangeState(new State_Move());
	}

	if (CInput::Instance()->KetPressedCheck(DIK_A))
	{
		Player::Instance()->SetCode(eSTATE::ATTACK);
		Player::Instance()->ChangeImage(ImageManager::Instance()->Player_Attack());
		Player::Instance()->ChangeState(new State_Attack());
	}
}

bool State_Stay::MoveCheck()
{
	if (CInput::Instance()->KetPressedCheck(DIK_LEFT) || CInput::Instance()->KetPressedCheck(DIK_RIGHT)
		|| CInput::Instance()->KetPressedCheck(DIK_DOWN) || CInput::Instance()->KetPressedCheck(DIK_UP))
		return true;

	return false;
}