#ifndef ENEMY_H
#define ENEMY_H

#include "Global.h"
#include "RenderObject.h"

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

private:
	std::shared_ptr<RenderObject> m_graphics;
	float m_xpos;
	float m_ypos;
	float m_width;
	float m_moveSpeed;
	int m_moveDir;
};

#endif ENEMY_H