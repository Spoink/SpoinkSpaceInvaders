#ifndef MISSILE_H
#define MISSILE_H

#include "Global.h"
#include "RenderObject.h"

class Missile
{
public:
	Missile(std::shared_ptr<RenderObject> graphics);
	~Missile();

	void Update();
	void ToggleActive(bool isActive);
	void SetPosition(int xpos, int ypos);
	void SetMoveDirection(int dir);
	bool IsActive();

private:
	std::shared_ptr<RenderObject> m_graphics;
	bool m_isActive;
	float m_moveSpeed;
	float m_xpos;
	float m_ypos;
	float m_height;
	int m_moveDir;

	void Move();
	void CheckIfOOB();
};

#endif MISSILE_H