#include "Player.h"
#include "ImageManager.h"
#include "Input.h"

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
}

void Player::Initialize()
{
	m_player = ImageManager::Instance()->Player();
}

void Player::MoveX(float _x)
{
	m_player.setX(m_player.getX() + _x);
}

void Player::MoveY(float _y)
{
	m_player.setY(m_player.getY() + _y);
}

void Player::Move()
{
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
	Move();
}

void Player::Render()
{
	m_player.draw();
}
