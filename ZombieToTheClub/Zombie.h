#pragma once
#include "image.h"
#include "Resource.h"
#include "AI_State.h"
#include "Time.h"

class Zombie
{
protected:
	Image m_image;
	Image m_attackCollisionBox;
	Image m_hitCollisionBox;
	Image m_traceCollisionBox;
	Time m_time;
	Time m_traceTime;

	int m_directionX;
	int m_directionY;
	int m_PatrolCount;

	eSTATE m_code;
	eTYPE m_type;

	AI_State * m_pstate;

	
	bool m_isarrive;
	bool m_isTrace;

	int m_hp;
	int m_atk;
	float m_moveSpeed;
	float atdSpeed;
	int m_experience;
	int m_score;
	int m_aniSpeed;

	bool m_batk;
	bool m_isdeath;
public:
	Zombie();
	~Zombie();
	
	virtual void initialize();
	virtual void Render();
	virtual void Update();
	virtual void MoveX(float _x);
	virtual void MoveY(float _y);
	virtual void Move();

	virtual void SetDirection(int _x=0, int _y=0 );
	virtual bool Tracing();

	virtual bool IsDie();
	virtual bool Hit();
	virtual bool Attack();
	virtual void SetCoordinate(int _x , int _y);
	bool Attackable();
	bool Targeting();

	virtual void ChangeState(eSTATE _state);
	void ChangeImage(Image _image);

	void SetCode(eSTATE _code);
	void SetAniSpeed(int _speed);
	void SetHp(int _atk);
	void SetIsAtk(bool _isAtk);
	void SetDeath(bool _death);

	Image GetImage() const;
	Image GetAttackCollisionBox() const;
	Image GetHitCollisionBox() const;
	Image GetTraceCollsionBox() const;
	int GetCurrentFrame() const;
	int GetFrame() const;
	int GetType() const;
	int GetAtk() const;
	bool GetIsAtk() const;
	int GetPatrolCount() const;
	virtual int GetX() const;
	virtual int GetY() const;
	virtual float GetRadius() const;
	float GetCenterX() const;
	float GetCenterY() const;
	int GetCode() const;
	int GetScore() const;
	bool IsDeath() const;
};

