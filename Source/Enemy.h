#ifndef ENEMY_H
#define ENEMY_H

#include "Global.h"
#include "RenderObject.h"
#include "CollisionManager.h"

class Enemy
{
public:
	Enemy(std::shared_ptr<RenderObject> graphics);
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

	void Destroy();
};

#endif ENEMY_H