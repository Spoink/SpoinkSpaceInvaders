#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Global.h"
#include "CollisionObject.h"

class CollisionManager
{
public:	
	CollisionManager();
	~CollisionManager();

	static void AddObject(std::shared_ptr<CollisionObject> collisionObject);
	static void CleanupList();

	void Update();

private:
	static std::vector<std::shared_ptr<CollisionObject>> collisionObjects;

	void ClearCollisionData();
	void CheckForCollisions();
};

#endif COLLISIONMANAGER_H