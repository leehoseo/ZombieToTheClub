#pragma once
#include "image.h"
#include "Resource.h"
#include "AI_State.h"
#include "Time.h"

struct ZombieCoordinate
{
	int x;
	int y;
};

class Zombie
{
protected:
	Image m_image;
	Image m_attackCollisionBox;
	Image m_hitCollisionBox;
	Image m_traceCollisionBox;
	Time m_time;

	int m_directionX;
	int m_directionY;
	int m_PatrolCount;

	eSTATE m_code;
	eTYPE m_type;

	AI_State * m_pstate;

	
	bool m_isarrive;

	int m_hp;
	int m_atk;
	float m_moveSpeed;
	float atdSpeed;
	int m_experience;
	int m_score;
	int m_aniSpeed;

	bool m_bAtk;
public:
	Zombie();
	~Zombie();
	
	virtual void initialize(float _x , float _y , Image _image, AI_State *_state);
	virtual void Render();
	virtual void Update();
	virtual void MoveX(float _x);
	virtual void MoveY(float _y);
	virtual int GetX();
	virtual int GetY();
	virtual void Move();
	virtual void SetDirection(int _x = 0 , int _y = 0 );
	virtual bool IsDie();
	virtual bool Hit();

	virtual float GetRadius() const;

	float GetCenterX() const;
	float GetCenterY() const;

	int GetCode() const;

	void SetCode(eSTATE _code);

	void ChangeState(eSTATE _state);
	void ChangeImage(Image _image);

	int GetCurrentFrame() const;
	int GetFrame() const;

	int GetType() const;
	void SetAniSpeed(int _speed);
	int GetAtk() const;
	void SetHp(int _atk);
	Image GetImage() const;
	Image GetAttackCollisionBox() const;
	Image GetHitCollisionBox() const;
	Image GetTraceCollsionBox() const;
	bool IsAtk();

	void SetIsAtk(bool _isAtk);
	bool GetIsAtk() const;
	bool Targeting();
	int GetPatrolCount() const;
	
};

