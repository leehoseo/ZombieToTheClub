#include "Boy_Zombie1.h"
#include "ImageManager.h"
#include <time.h>
#include <stdlib.h>
#include "AI_State_Move.h"
#include "AI_State_Stay.h"
#include "AI_State_Attack.h"
#include "AI_State_Hit.h"
#include "AI_State_Death.h"
#include "AI_State_Trace.h"
#include "ImageManager.h"
#include "Sound.h"

Boy_Zombie1::Boy_Zombie1()
{
}

Boy_Zombie1::~Boy_Zombie1()
{
}

void Boy_Zombie1::initialize()
{
	if (rand() % 2)
	{
		ChangeState(eSTATE::STAY);
	}
	else
	{
		ChangeState(eSTATE::MOVE);
	}

	m_image.setX(rand() % (GAME_WIDTH - 148) + 10);
	m_image.setY(rand() % 590);

	m_attackCollisionBox = ImageManager::Instance()->AttackCollisionBox();
	m_hitCollisionBox = ImageManager::Instance()->HitCollisionBox();
	m_traceCollisionBox = ImageManager::Instance()->TraceCollsionBox();

	m_hitCollisionBox.setY(m_image.getY());

	m_traceCollisionBox.setX(m_image.getX() - 100);
	m_traceCollisionBox.setY(m_image.getY() - 100);

	m_attackCollisionBox.setY(m_image.getCenterY() - 40);

	m_directionX = rand() % (GAME_WIDTH - 148) + 10;
	m_directionY = rand() % 590;

	m_hp = 35;
	m_atk = 8;
	m_moveSpeed = 0.5;
	atdSpeed = 2;
	m_experience = 5;
	m_score = 100;
	m_type = eTYPE::BZ;
	m_aniSpeed = 200;
}

void Boy_Zombie1::ChangeState(eSTATE _state)
{
	SetCode(_state);

	m_PatrolCount = 0;
	switch (_state)
	{
	case eSTATE::ATTACK1:
		if (GetIsAtk() == false)
			break;
		ChangeImage(ImageManager::Instance()->BZ1_Attack());
		m_pstate = AI_State_Attack::Instance();
		break;
	case eSTATE::HIT:
		Sound::Instance()->PlayZombieHit();
		ChangeImage(ImageManager::Instance()->BZ1_Hit());
		m_pstate = AI_State_Hit::Instance();
		break;
	case eSTATE::MOVE:
		ChangeImage(ImageManager::Instance()->BZ1_Move());
		m_pstate = AI_State_Move::Instance();
		break;
	case eSTATE::STAY:
		ChangeImage(ImageManager::Instance()->BZ1_Stay());
		m_pstate = AI_State_Stay::Instance();
		break;
	case eSTATE::DEATH:
		Sound::Instance()->PlayZombieDeath();
		ChangeImage(ImageManager::Instance()->BZ1_Death());
		m_pstate = AI_State_Death::Instance();
		break;
	case eSTATE::TRACE:
		ChangeImage(ImageManager::Instance()->BZ1_Trace());
		m_pstate = AI_State_Trace::Instance();
		break;
	}
}
