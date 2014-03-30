#ifndef ENEMY_H
#define ENEMY_H

#include "Global.h"
#include "RenderObject.h"
#include "CollisionManager.h"

class Enemy
{
public:
	enum EnemyType
	{
		EnemyType_One = 0,
		EnemyType_Two,
		EnemyType_Three,
		EnemyType_Four
	};
	
	Enemy(EnemyType enemyType, std::shared_ptr<RenderObject> graphics);
	~Enemy();

	void Update();
	bool HasHitBounderies();
	
	void SetPosition(int xpos, int ypos);
	void SetMoveDir(int moveDir);
	int GetMoveDir();
	bool IsAlive();

private:
	std::shared_ptr<RenderObject> m_graphics;
	std::shared_ptr<CollisionObject> m_collisionObject;
	float m_xpos;
	float m_ypos;
	float m_width;
	float m_moveSpeed;
	int m_moveDir;
	bool m_isAlive;
	EnemyType m_enemyType;

	void Destroy();
};

#endif ENEMY_H