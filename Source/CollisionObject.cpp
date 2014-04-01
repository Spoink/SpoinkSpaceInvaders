#include "CollisionObject.h"

CollisionObject::CollisionObject(std::string name, CollisionObject::CollisionLayer layer, std::shared_ptr<SDL_Rect> collisionBox) 
{
	m_name = name;
	m_layer = layer;
	m_collisionBox = collisionBox;
	m_removeObject = false;
	m_collisionData = NULL;
}

CollisionObject::~CollisionObject() {}

std::string CollisionObject::Name()
{ return m_name; }

void CollisionObject::ToggleRemove(bool shouldRemove)
{ m_removeObject = shouldRemove; }

bool CollisionObject::ShouldRemove()
{ return m_removeObject; }

std::shared_ptr<SDL_Rect> CollisionObject::GetRect()
{ return m_collisionBox; }

std::shared_ptr<CollisionData> CollisionObject::GetCollisionData()
{ return m_collisionData; }

CollisionObject::CollisionLayer CollisionObject::GetLayer()
{ return m_layer; }

void CollisionObject::SetCollisionData(std::shared_ptr<CollisionObject> otherCollider)
{ 
	m_collisionData = std::shared_ptr<CollisionData>(new CollisionData());
	m_collisionData->Collider = otherCollider;
}

bool CollisionObject::CheckCollision(std::shared_ptr<SDL_Rect> otherBox)
{
	if(otherBox->x > (m_collisionBox->x + m_collisionBox->w))
	{ return false; }
	else if((otherBox->x + otherBox->w) < m_collisionBox->x)
	{ return false; }
	else if(otherBox->y > (m_collisionBox->y + m_collisionBox->h))
	{ return false; }
	else if((otherBox->y + otherBox->h) < m_collisionBox->y)
	{ return false; }  

	return true;
}

void CollisionObject::ClearCollisionData()
{ 
	m_collisionData.reset(); 
	m_collisionData = NULL;
}