#include "LeftHand.h"



LeftHand::LeftHand()
{
	Initialize();
}


LeftHand::~LeftHand()
{
}

void LeftHand::Initialize()
{
	m_image = ImageManager::Instance()->LeftHandStay();
	m_code = eHAND::STAND;
}

void LeftHand::Update()
{
	if (false == AniEnd() && m_code != eHAND::STAND)
	{
		m_image = ImageManager::Instance()->LeftHandStay();
	}
	m_image.update(400);
}

void LeftHand::Render()
{
	m_image.draw();
}

void LeftHand::ChangeAni(Image _image)
{
	m_code = eHAND::ANOTHER;
	m_image = _image;
}

bool LeftHand::AniEnd()
{
	if (m_image.GetCurrentFrame() == m_image.GetFrame())
	{
		return false;
	}
	return true;
}
