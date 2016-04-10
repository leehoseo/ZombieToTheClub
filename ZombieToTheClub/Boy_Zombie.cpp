#include "Boy_Zombie.h"
#include "ImageManager.h"
#include <time.h>
#include <stdlib.h>

Boy_Zombie::Boy_Zombie()
{
}

Boy_Zombie::~Boy_Zombie()
{
}

void Boy_Zombie::initialize(float _x, float _y, Image _image, AI_State * _state)
{
	m_image = _image;
	m_image.setX(_x);
	m_image.setY(_y);

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
	m_pstate = _state;
	m_aniSpeed = 200;
}
