#pragma once
#include "image.h"
#include "State.h"
#include "Zombie.h"
#include "CrashCheck.h"

struct AttackDirection
{
	bool m_direction[8];
};

class Player
{
private:

	Player();
	Image m_image;
	Image m_attackCollisionBox;
	Image m_hitCollisionBox;
	State * m_pstate;
	eSTATE m_code;
	eTYPE m_type;
	AttackDirection m_attackDirection;

	int m_atk;
	int m_hp;
	float m_moveSpeed;
	float m_atkSpeed;
	int m_gold;
	int m_experience;

public:

	static Player * Instance();
	~Player();

	void Initialize();
	void Update();
	void Render();

	void MoveX(float _x);
	void MoveY(float _y);
	void Move();
	void Hit(Zombie _zombie);
	bool IsDie();

	void AttackMove();
	bool IsAttack();
	void ChangeState(eSTATE _state);
	void ChangeImage(Image _image);
	void ResetDirection();

	Image GetImage() const;
	Image GetAttackCollisionBox() const;
	Image GetHitCollisionBox() const;
	AttackDirection GetAttackDirection() const;
	int GetX() const;
	int GetY() const;
	int GetCurrentFrame() const;
	int GetFrame() const;
	int GetCode() const;
	int GetType() const;
	float GetRadius() const;
	float GetCenterX() const;
	float GetCenterY() const;
	int GetAtk() const;
	int GetHp() const;
	
	void SetCode(eSTATE _code);
	
};
