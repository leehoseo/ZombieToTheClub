#include "RightHand.h"



RightHand::RightHand()
{
	Initialize();
}


RightHand::~RightHand()
{
}

void RightHand::Initialize()
{
	m_image = ImageManager::Instance()->RightHandStay();
	m_code = eHAND::STAND;
}

void RightHand::Update()
{
	if (false == AniEnd() && m_code != eHAND::STAND)
	{
		m_image = ImageManager::Instance()->RightHandStay();
	}

	m_image.update(400);
}

void RightHand::Render()
{
	m_image.draw();
}

void RightHand::ChangeAni(Image _image)
{
	m_code = eHAND::ANOTHER;
	m_image = _image;
}

bool RightHand::AniEnd()
{
	if (m_image.GetCurrentFrame() == m_image.GetFrame())
	{
		return false;
	}
	return true;
}
