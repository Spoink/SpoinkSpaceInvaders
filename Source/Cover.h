#ifndef COVER_H
#define COVER_H

#include "Global.h"
#include "RenderObject.h"
#include "CollisionManager.h"

class Cover
{
public:
	Cover(int xpos, int ypos);
	~Cover();

	void Update();

private:
	std::shared_ptr<RenderObject> m_graphics;
	std::shared_ptr<CollisionObject> m_collisionObject;
	int m_hitPoints;

	void ChangeGraphics();
};

#endif COVER_H