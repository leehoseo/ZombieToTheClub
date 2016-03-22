#include "Player.h"
#include "ImageManager.h"
#include "Input.h"
#include "State_Stay.h"

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
}

void Player::MoveX(float _x)
{
	m_image.setX(m_image.getX() + _x);
}

void Player::MoveY(float _y)
{
	m_image.setY(m_image.getY() + _y);
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
	m_pstate->Update();
	m_image.update();
}

void Player::Render()
{
	m_pstate->Render();
	m_image.draw();
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