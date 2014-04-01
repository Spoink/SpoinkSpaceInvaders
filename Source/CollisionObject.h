#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H

#include "Global.h"

struct CollisionData;

class CollisionObject
{
public:
	enum CollisionLayer
	{
		All,
		Player,
		Enemy
	};
	
	CollisionObject(std::string name, CollisionLayer layer, std::shared_ptr<SDL_Rect> collisionBox);
	~CollisionObject();

	std::string Name();
	void ToggleRemove(bool shouldRemove);
	bool ShouldRemove();
	
	std::shared_ptr<SDL_Rect> GetRect();
	std::shared_ptr<CollisionData> GetCollisionData();
	CollisionLayer GetLayer();

	void SetCollisionData(std::shared_ptr<CollisionObject>collisionData);
	
	bool CheckCollision(std::shared_ptr<SDL_Rect> otherCollider);
	void ClearCollisionData();

private:	
	std::string m_name;
	CollisionLayer m_layer;
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