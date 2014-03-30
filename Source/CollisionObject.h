#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H

#include "Global.h"

struct CollisionData;

class CollisionObject
{
public:
	CollisionObject(std::string name, std::shared_ptr<SDL_Rect> collisionBox);
	~CollisionObject();

	std::string Name();
	void ToggleRemove(bool shouldRemove);
	bool ShouldRemove();
	std::shared_ptr<SDL_Rect> GetRect();
	bool CheckCollision(std::shared_ptr<SDL_Rect> otherCollider);
	void SetCollisionData(std::shared_ptr<CollisionObject>collisionData);
	std::shared_ptr<CollisionData> GetCollisionData();
	void ClearCollisionData();

private:
	std::string m_name;
	std::shared_ptr<SDL_Rect> m_collisionBox;
	std::shared_ptr<CollisionData> m_collisionData;
	bool m_removeObject;
};

struct CollisionData
{
public:
	std::shared_ptr<CollisionObject> Collider;
};

#endif COLLISIONOBJECT_H