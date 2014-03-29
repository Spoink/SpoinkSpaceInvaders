#include "CollisionManager.h"

std::vector<std::shared_ptr<CollisionObject>> CollisionManager::collisionObjects;

CollisionManager::CollisionManager() {}
CollisionManager::~CollisionManager() {}

void CollisionManager::AddObject(std::shared_ptr<CollisionObject> collisionObject)
{ collisionObjects.push_back(collisionObject); }

void CollisionManager::CleanupList()
{
	for(int i = collisionObjects.size() - 1; i > -1; i--)
	{ 
		if(collisionObjects[i]->ShouldRemove())
		{ collisionObjects.erase(collisionObjects.begin() + i); }
	}
}

void CollisionManager::Update()
{
	ClearCollisionData();
	CheckForCollisions(); 
}

void CollisionManager::ClearCollisionData()
{
	for(unsigned int i = 0; i < collisionObjects.size(); i++)
	{ collisionObjects[i]->ClearCollisionData(); }
}

void CollisionManager::CheckForCollisions()
{
	for(unsigned int i = 0; i < collisionObjects.size(); i++)
	{
		for(unsigned int m = 0; m < collisionObjects.size(); m++)
		{
			if(collisionObjects[i]->GetCollisionData() != NULL)
			{ break; }
			if(i == m)
			{ continue; }

			collisionObjects[i]->CheckCollision(collisionObjects[m]);
		}
	}
}