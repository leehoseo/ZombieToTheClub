#include "Player.h"
#include "ImageManager.h"
#include "Input.h"
#include "State_Stay.h"
#include <stdio.h>
Player::Player()
{
	Initialize();
}


Player * Player::Instance()
{
	static Player instance;
	return &instance;
}

Player::~Player()
{
	SAFE_DELETE(m_pstate);
}

void Player::Initialize()
{
	m_pstate = new State_Stay();
	m_image = ImageManager::Instance()->Player_Stay();
	m_test = ImageManager::Instance()->Test();
	m_code = eCODE::STAY;

	m_atk = 10;
	m_hp = 100;
	m_moveSpeed = 0.1;
	m_atkSpeed = 0.5;
	m_gold = 0;
	m_experience = 0;
}

void Player::MoveX(float _x)
{
	if (_x < 0)
		m_image.flipHorizontal(true);
	else if(_x > 0)
		m_image.flipHorizontal(false);

	m_image.setX(m_image.getX() + _x);
}

void Player::MoveY(float _y)
{
	m_image.setY(m_image.getY() + _y);
}

void Player::Move()
{
	if (CInput::Instance()->KetPressedCheck(DIK_LEFT) && CInput::Instance()->KetPressedCheck(DIK_UP))
	{
		MoveX(-1);
		MoveY(-1);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_LEFT) && CInput::Instance()->KetPressedCheck(DIK_DOWN))
	{
		MoveX(-1);
		MoveY(+1);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_RIGHT) && CInput::Instance()->KetPressedCheck(DIK_UP))
	{
		MoveX(+1);
		MoveY(-1);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_RIGHT) && CInput::Instance()->KetPressedCheck(DIK_DOWN))
	{
		MoveX(+1);
		MoveY(+1);
		return;
	}

	switch (CInput::Instance()->KeyBoardPressed())
	{
	case DIK_LEFT:
		MoveX(-1);
		return;
	case DIK_RIGHT:
		MoveX(+1);
		return;
	case DIK_UP:
		MoveY(-1);
		return;
	case DIK_DOWN:
		MoveY(+1);
		return;
	}
}

void Player::Update()
{
	m_test.setX(m_image.getCenterX() - 20);
	m_test.setY(m_image.getCenterY());
	m_pstate->Update();
	m_image.update(100);
}

void Player::Render()
{
	m_image.draw();
	m_test.draw();
}

void Player::ChangeState(State * _newState)
{
	delete m_pstate;
	m_pstate = _newState;
	return;
}

void Player::ChangeImage(Image _image)
{
	int tempX = m_image.getX();
	int tempY = m_image.getY();

	m_image = _image;

	m_image.setX(tempX);
	m_image.setY(tempY);
}

int Player::GetX() const
{
	return m_image.getX();
}

int Player::GetY() const
{
	return m_image.getY();
}

int Player::GetCurrentFrame() const
{
	return m_image.GetCurrentFrame();
}

int Player::GetFrame() const
{
	return m_image.GetFrame();
}

int Player::GetCode() const
{
	return m_code;
}

void Player::SetCode(eCODE _code)
{
	m_code = _code;
}

float Player::GetRadius() const
{
	return m_image.getRadius();
}

float Player::GetCenterX() const
{
	return m_image.getCenterX();
}

float Player::GetCenterY() const
{
	return m_image.getCenterY();;
}

int Player::GetAtk() const
{
	return m_atk;
}
