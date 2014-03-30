#ifndef SPECIALENEMY_H
#define SPECIALENEMY_H

#include "Global.h"
#include "Enemy.h"

class SpecialEnemy
{
public:
	SpecialEnemy();
	~SpecialEnemy();

	void Update();

private:
	std::unique_ptr<Enemy> m_enemy;
	float m_nextSpawn;
	float m_xpos;
	float m_ypos;
	float m_width;
	float m_moveSpeed;

	void SpawnEnemy();
	void MoveEnemy();
	void CheckIfOOB();
	void CheckIfHit();
};

#endif SPECIALENEMY_H