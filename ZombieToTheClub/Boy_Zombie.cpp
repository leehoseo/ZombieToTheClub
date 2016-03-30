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
	m_collisionBox = ImageManager::Instance()->CollisionBox();

	m_image.setX(_x);
	m_image.setY(_y);

	m_hp = 35;
	m_atk = 8;
	m_moveSpeed = 0.5;
	atdSpeed = 2;
	m_experience = 5;
	m_score = 1;
	m_type = eTYPE::BZ;
	m_pstate = _state;
	m_aniSpeed = 200;
}
