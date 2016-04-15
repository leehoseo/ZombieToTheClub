#include "Player.h"
#include "ImageManager.h"
#include "Input.h"
#include "State_Stay.h"
#include "State_Attack.h"
#include "State_Attack2.h"
#include "State_Attack3.h"
#include "State_Move.h"
#include "State_Hit.h"
#include "State_Down.h"
#include <stdio.h>
#include "Sound.h"
#include "State_Death.h"

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
	m_image.setX(GAME_WIDTH/2 - 60);
	m_image.setY(GAME_HEIGHT/2 - 60);
	m_attackCollisionBox = ImageManager::Instance()->AttackCollisionBox();
	m_hitCollisionBox = ImageManager::Instance()->HitCollisionBox();
	m_hitCollisionBox.setX(m_image.getX() + 50);
	m_attackCollisionBox.setX(m_image.getCenterX() - 70);
	m_code = eSTATE::STAY;
	m_type = eTYPE::PLAYER;
	m_atk = 10;
	m_hp = 100;
	m_moveSpeed = 0.1;
	m_atkSpeed = 0.5;
	m_gold = 0;
	m_experience = 0;
	m_combo = 0;
	ResetDirection();
	m_comboTime.SetStartTime();
	m_hitTIme.SetStartTime();
	m_isHitAble = true;
	m_isDeath = false;
}

void Player::MoveX(float _x)
{
	if (_x < 0)
	{
		m_image.flipHorizontal(true);
		m_hitCollisionBox.setX(m_image.getX() + 50);
		m_attackCollisionBox.setX(m_image.getCenterX() - 70);
	}
	else if (_x > 0)
	{
		m_image.flipHorizontal(false);
		m_hitCollisionBox.setX(m_image.getX() + 30);
		m_attackCollisionBox.setX(m_image.getCenterX());
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

		if (10 > this->GetX() && 10 > this->GetY())
			return;

		if (10 > this->GetX())
		{
			MoveY(-5);
			return;
		}
		if (10 > this->GetY())
		{
			MoveX(-5);
			return;
		}


		MoveX(-5);
		MoveY(-5);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_LEFT) && CInput::Instance()->KetPressedCheck(DIK_DOWN))
	{
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::LEFT_DOWN] = true;

		if (10 > this->GetX() && 590 < this->GetY())
			return;

		if (10 > this->GetX())
		{
			MoveY(+5);
			return;
		}
		if (590 < this->GetY())
		{
			MoveX(-5);
			return;
		}
		
		MoveX(-5);
		MoveY(+5);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_RIGHT) && CInput::Instance()->KetPressedCheck(DIK_UP))
	{
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::RIGHT_UP] = true;

		if (GAME_WIDTH - 138 < this->GetX() && 10 > this->GetY())
			return;

		if (GAME_WIDTH - 138 < this->GetX())
		{
			MoveY(-5);
			return;
		}
		if (10 > this->GetY())
		{
			MoveX(+5);
			return;
		}
		
		MoveX(+5);
		MoveY(-5);
		return;
	}
	else if (CInput::Instance()->KetPressedCheck(DIK_RIGHT) && CInput::Instance()->KetPressedCheck(DIK_DOWN))
	{
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::RIGHT_DOWN] = true;

		if (GAME_WIDTH - 138 < this->GetX() && 590 < this->GetY())
			return;

		if (GAME_WIDTH - 138 < this->GetX())
		{
			MoveY(+5);
			return;
		}
		if (590 < this->GetY())
		{
			MoveX(+5);
			return;
		}
		MoveX(+5);
		MoveY(+5);
		return;
	}


	switch (CInput::Instance()->KeyBoardPressed())
	{
	case DIK_LEFT:
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::LEFT] = true;

		if (10 > this->GetX())
			return;

		MoveX(-5);
		return;
	case DIK_RIGHT:
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::RIGHT] = true;

		if (GAME_WIDTH - 138 < this->GetX())
			return;

		MoveX(+5);
		return;
	case DIK_UP:
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::UP] = true;

		if (10 > this->GetY())
			return;

		MoveY(-5);
		return;
	case DIK_DOWN:
		if (CInput::Instance()->KetPressedCheck(DIK_A))
			m_attackDirection.m_direction[eDIRECTION::DOWN] = true;

		if (590 < this->GetY())
			return;

		MoveY(+5);
		return;
	}
}

void Player::Update()
{
	m_comboTime.SetTime();
	m_attackCollisionBox.setY(m_image.getCenterY()-40);
	//m_hitCollisionBox.setX(m_image.getX()+20);
	m_hitCollisionBox.setY(m_image.getY());

	HitAble();
	m_pstate->Update();
	m_image.update(200);

	if (m_hp < 0 && GetCode() != eSTATE::DEATH)
	{
		ChangeState(eSTATE::DEATH);
	}

	if (m_comboTime.GetTime() > 3000)
	{
		m_combo = 0;
		m_comboTime.SetStartTime();
	}
}

void Player::Render()
{
	//m_attackCollisionBox.draw();
	//m_hitCollisionBox.draw();
	m_image.draw();
}

void Player::AttackMove()
{
	if (GetAttackDirection().m_direction[eDIRECTION::LEFT])
	{
		if (10 > this->GetX())
			return;

		MoveX(-2);
		return;
	}

	else if (GetAttackDirection().m_direction[eDIRECTION::RIGHT])
	{
		if (GAME_WIDTH - 138 < this->GetX())
			return;

		MoveX(+2);
		return;
	}

	else if (GetAttackDirection().m_direction[eDIRECTION::UP])
	{
		if (10 > this->GetY())
			return;

		MoveY(-2);
		return;
	}

	else if (GetAttackDirection().m_direction[eDIRECTION::DOWN])
	{
		if (590 < this->GetY())
			return;
		MoveY(+2);
		return;
	}

	else if (GetAttackDirection().m_direction[eDIRECTION::LEFT_UP])
	{
		if (10 > this->GetX() && 10 > this->GetY())
			return;

		if (10 > this->GetX())
		{
			MoveY(-2);
			return;
		}
		if (10 > this->GetY())
		{
			MoveX(-2);
			return;
		}
		MoveX(-2);
		MoveY(-2);
		return;
	}

	else if (GetAttackDirection().m_direction[eDIRECTION::LEFT_DOWN])
	{
		if (10 > this->GetX() && 590 < this->GetY())
			return;

		if (10 > this->GetX())
		{
			MoveY(+2);
			return;
		}
		if (590 < this->GetY())
		{
			MoveX(-2);
			return;
		}

		MoveX(-2);
		MoveY(+2);
		return;
	}

	else if (GetAttackDirection().m_direction[eDIRECTION::RIGHT_UP])
	{
		if (GAME_WIDTH - 138 < this->GetX() && 10 > this->GetY())
			return;

		if (GAME_WIDTH - 138 < this->GetX())
		{
			MoveY(-2);
			return;
		}
		if (10 > this->GetY())
		{
			MoveX(+2);
			return;
		}

		MoveX(+2);
		MoveY(-2);
		return;
	}

	else if (GetAttackDirection().m_direction[eDIRECTION::RIGHT_DOWN])
	{
		if (GAME_WIDTH - 138 < this->GetX() && 590 < this->GetY())
			return;

		if (GAME_WIDTH - 138 < this->GetX())
		{
			MoveY(+2);
			return;
		}
		if (590 < this->GetY())
		{
			MoveX(+2);
			return;
		}

		MoveX(+2);
		MoveY(+2);
		return;
	}

	if (GetImage().GetHorizontal())
	{
		if (10 > this->GetX())
			return;
		MoveX(-2);
	}
	else
	{
		if (GAME_WIDTH - 138 < this->GetX())
			return;
		MoveX(+2);
	}
}

bool Player::IsAttack()
{
	if (CInput::Instance()->KetPressedCheck(DIK_A))
	{
		return true;
	}
	else
		return false;
}

void Player::ChangeState(eSTATE _state)
{
	SetCode(_state);

	switch (_state)
	{
	case eSTATE::ATTACK1: 
		Sound::Instance()->PlayAttack1();
		ChangeImage(ImageManager::Instance()->Player_Attack1());
		delete m_pstate;
		m_pstate = new State_Attack();
		break;
	case eSTATE::ATTACK2:
		Sound::Instance()->PlayAttack1();
		ChangeImage(ImageManager::Instance()->Player_Attack2());
		delete m_pstate;
		m_pstate = new State_Attack2();
		break;

	case eSTATE::ATTACK3:
		Sound::Instance()->PlayAttack1();
		ChangeImage(ImageManager::Instance()->Player_Attack3());
		delete m_pstate;
		m_pstate = new State_Attack3();
		break;
	case eSTATE::HIT:
		ChangeImage(ImageManager::Instance()->Player_Hit());
		ResetDirection();
		delete m_pstate;
		m_pstate = new State_Hit();
		break;
	case eSTATE::MOVE:
		ChangeImage(ImageManager::Instance()->Player_Move());
		ResetDirection();
		delete m_pstate;
		m_pstate = new State_Move();
		break;
	case eSTATE::STAY:
		ChangeImage(ImageManager::Instance()->Player_Stay());
		ResetDirection();
		delete m_pstate;
		m_pstate = new State_Stay();
		break;
	case eSTATE::HIT_DOWN:
		Sound::Instance()->PlayPlayerDown();
		ChangeImage(ImageManager::Instance()->Player_Down());
		ResetDirection();
		delete m_pstate;
		m_pstate = new State_Down();
		break;
	case eSTATE::DEATH:
		Sound::Instance()->EndMusic();
		Sound::Instance()->PlayPlayerDeath();
		ChangeImage(ImageManager::Instance()->Player_Death());
		ResetDirection();
		delete m_pstate;
		m_pstate = new State_Death();
		break;
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

void Player::HitAble()
{
	if (GetCode() == eSTATE::HIT)
		m_isHitAble = false;

	if (false == m_isHitAble)
	{
		if (true == m_hitTIme.Timer(1000))
		{
			printf("hkhkhk");
			m_isHitAble = true;
		}
	}
}

void Player::SetCode(eSTATE _code)
{
	m_code = _code;
}

void Player::SetComboTime()
{
	m_comboTime.SetStartTime();
}

void Player::AddCombo(int _combo)
{
	m_combo += _combo;
}

void Player::ResetHitCount()
{
	m_nHitCount += 1;
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

int Player::GetHp() const
{
	return m_hp;
}

int Player::GetCombo() const
{
	return m_combo;
}

int Player::GetHitCount() const
{
	return m_nHitCount;
}

bool Player::GetHitAble() const
{
	return m_isHitAble;
}

Image Player::GetImage() const
{
	return m_image;
}

Image Player::GetAttackCollisionBox() const
{
	return m_attackCollisionBox;
}

Image Player::GetHitCollisionBox() const
{
	return m_hitCollisionBox;
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

void Player::Hit(Zombie _zombie)
{
	m_nHitCount += 1;
	m_hp -= _zombie.GetAtk();
	if (m_nHitCount == 3)
	{
		ChangeState(eSTATE::HIT_DOWN);
		m_nHitCount = 0;
	}
}

void Player::IsDie()
{
	 m_isDeath = true;
}

bool Player::GetDeath() const
{
	return m_isDeath;
}
