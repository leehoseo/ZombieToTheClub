﻿#include "State_Move.h"
#include "ImageManager.h"
#include "Input.h"
#include "State_Stay.h"
#include "State_Attack.h"
#include "ImageManager.h"
#include "Player.h"
#include "Resource.h"
State_Move::State_Move()
{
	//Player::Instance()->SetCode(eCODE::MOVE);
}


State_Move::~State_Move()
{
}

void State_Move::Update()
{
	Move();
	if (!MoveCheck())
	{
		Player::Instance()->ChangeState(eSTATE::STAY);
	}

	if (CInput::Instance()->KetPressedCheck(DIK_A))
	{
		Player::Instance()->ChangeState(eSTATE::ATTACK);
	}
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