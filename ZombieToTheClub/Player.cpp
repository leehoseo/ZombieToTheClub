#include "Player.h"
#include "ImageManager.h"
#include "Input.h"
#include "State_Stay.h"
#include "State_Attack.h"
#include "State_Move.h"
#include "State_Hit.h"
#include <stdio.h>
Player::Player()
{
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
	m_collisionBox = ImageManager::Instance()->CollisionBox();
	m_code = eSTATE::STAY;
	m_type = eTYPE::PLAYER;
	m_atk = 10;
	m_hp = 100;
	m_moveSpeed = 0.1;
	m_atkSpeed = 0.5;
	m_gold = 0;
	m_experience = 0;
	ResetDirection();
}

void Player::MoveX(float _x)
{
	if (_x < 0)
	{
		m_image.flipHorizontal(true);
		m_collisionBox.flipHorizontal(true);
	}
	else if (_x > 0)
	{
		m_image.flipHorizontal(false);
		m_collisionBox.flipHorizontal(false);
	}

	m_image.setX(m_image.getX() + _x);
}

void Player::MoveY(float _y)
{
	m_image.setY(m_image.getY() + _y);
}

void Player::Move()
{
	//Move
	if (CInput::Instance()->KetPressedCheck(DIK_LEFT) && CInput::Instance()->KetPressedCheck(DIK_UP))
	{
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::LEFT_UP] = true;

		MoveX(-5);
		MoveY(-5);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_LEFT) && CInput::Instance()->KetPressedCheck(DIK_DOWN))
	{
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::LEFT_DOWN] = true;

		MoveX(-5);
		MoveY(+5);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_RIGHT) && CInput::Instance()->KetPressedCheck(DIK_UP))
	{
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::RIGHT_UP] = true;

		MoveX(+5);
		MoveY(-5);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_RIGHT) && CInput::Instance()->KetPressedCheck(DIK_DOWN))
	{
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::RIGHT_DOWN] = true;

		MoveX(+5);
		MoveY(+5);
		return;
	}


	switch (CInput::Instance()->KeyBoardPressed())
	{
	case DIK_LEFT:
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::LEFT] = true;
		MoveX(-5);
		return;
	case DIK_RIGHT:
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::RIGHT] = true;
		MoveX(+5);
		return;
	case DIK_UP:
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::UP] = true;
		MoveY(-5);
		return;
	case DIK_DOWN:
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::DOWN] = true;
		MoveY(+5);
		return;
	}
}

void Player::Update()
{
	printf("%d\n", m_hp);
	m_collisionBox.setX(m_image.getCenterX());
	m_collisionBox.setY(m_image.getCenterY());
	m_pstate->Update();
	m_image.update(100);
}

void Player::Render()
{
	m_image.draw();
	m_collisionBox.draw();
}

void Player::ChangeState(eSTATE _state)
{
	SetCode(_state);
	switch (_state)
	{
	case eSTATE::ATTACK: 
		ChangeImage(ImageManager::Instance()->Player_Attack());
		ResetDirection();

		delete m_pstate;
		m_pstate = new State_Attack();
		return;
	case eSTATE::HIT:
		ChangeImage(ImageManager::Instance()->Player_Hit());

		delete m_pstate;
		m_pstate = new State_Hit();
		return;
	case eSTATE::MOVE:
		ChangeImage(ImageManager::Instance()->Player_Move());

		delete m_pstate;
		m_pstate = new State_Move();
		return;
	case eSTATE::STAY:
		ChangeImage(ImageManager::Instance()->Player_Stay());

		delete m_pstate;
		m_pstate = new State_Stay();
		return;
	}
}

void Player::ChangeImage(Image _image)
{
	int tempX = m_image.getX();
	int tempY = m_image.getY();
	bool tempH = m_image.GetHorizontal();

	m_image = _image;

	m_image.setX(tempX);
	m_image.setY(tempY);
	m_image.flipHorizontal(tempH);
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

void Player::SetCode(eSTATE _code)
{
	m_code = _code;
}

int Player::GetType() const
{
	return m_type;
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

Image Player::GetImage() const
{
	return m_image;
}

Image Player::GetCollisionBox() const
{
	return m_collisionBox;
}

AttackDirection Player::GetAttackDirection() const
{
	return m_attackDirection;
}

void Player::ResetDirection()
{
	for (int index = 0; index < 8; ++index)
		m_attackDirection.m_direction[index] = false;
}

bool Player::Hit(Zombie _zombie)
{
	if (CrashCheck::Instance()->Rect_Rect(GetCollisionBox(), _zombie.GetCollisionBox()) && _zombie.GetCode() == eSTATE::ATTACK)
	{
		m_hp -= _zombie.GetAtk();
		return true;
	}
	return false;
}

bool Player::IsDie()
{
	if (m_hp < 0)
		return true;
	else
		return false;
}
