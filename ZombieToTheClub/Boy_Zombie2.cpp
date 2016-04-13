#include "Boy_Zombie2.h"
#include "AI_State_Move.h"
#include "AI_State_Stay.h"
#include "AI_State_Attack.h"
#include "AI_State_Hit.h"
#include "AI_State_Death.h"
#include "ImageManager.h"

Boy_Zombie2::Boy_Zombie2()
{
}


Boy_Zombie2::~Boy_Zombie2()
{
}

void Boy_Zombie2::initialize()
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

void Boy_Zombie2::ChangeState(eSTATE _state)
{
	SetCode(_state);

	m_PatrolCount = 0;
	switch (_state)
	{
	case eSTATE::ATTACK1:
		if (GetIsAtk() == false)
			return;
		ChangeImage(ImageManager::Instance()->BZ2_Attack());
		m_pstate = AI_State_Attack::Instance();
		return;
	case eSTATE::HIT:
		ChangeImage(ImageManager::Instance()->BZ2_Hit());
		m_pstate = AI_State_Hit::Instance();
		return;
	case eSTATE::MOVE:
		ChangeImage(ImageManager::Instance()->BZ2_Move());
		m_pstate = AI_State_Move::Instance();
		return;
	case eSTATE::STAY:
		ChangeImage(ImageManager::Instance()->BZ2_Stay());
		m_pstate = AI_State_Stay::Instance();
		return;
	case eSTATE::DEATH:
		ChangeImage(ImageManager::Instance()->BZ2_Death());
		m_pstate = AI_State_Death::Instance();
	}
}
