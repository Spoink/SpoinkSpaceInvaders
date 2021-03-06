#include "Missile.h"
#include "Time.h"
#include "Settings.h"
#include "Gui.h"

Missile::Missile(CollisionObject::CollisionLayer layer, std::shared_ptr<RenderObject> graphics) 
{ 
	m_graphics = graphics; 
	m_isActive = false;

	m_xpos = (float)m_graphics->GetRect()->x;
	m_ypos = (float)m_graphics->GetRect()->y;
	m_height = (float)m_graphics->GetRect()->h;
	m_moveDir = 1;
	m_moveSpeed = 400.0f;

	m_collisionObject = std::shared_ptr<CollisionObject>(new CollisionObject("Missile", layer, m_graphics->GetRect()));

	m_graphics->ToggleVisibility(false);
}

Missile::~Missile() 
{ 
	Gui::RemoveGuiObject(m_graphics); 
	m_collisionObject->ToggleRemove(true);
}

void Missile::Update()
{ 
	if(!m_isActive)
	{ return; }

	Move();
	CheckIfOOB();

	if(m_collisionObject->GetCollisionData() != NULL)
	{ ToggleActive(false); }
}

void Missile::ToggleActive(bool isActive)
{ 
	m_isActive = isActive; 
	m_graphics->ToggleVisibility(m_isActive);

	if(m_isActive)
	{
		m_collisionObject->ToggleRemove(false);
		CollisionManager::AddObject(m_collisionObject); 
	}
	else
	{
		m_collisionObject->ToggleRemove(true);
		CollisionManager::CleanupList();
		m_collisionObject->ClearCollisionData();
		SetPosition(-100, -100);
	}
}

void Missile::SetPosition(int xpos, int ypos)
{ 
	m_xpos = (float)xpos;
	m_ypos = (float)ypos;
	m_graphics->SetPosition((int)m_xpos, (int)m_ypos); 
}

void Missile::SetMoveDirection(int direction)
{ m_moveDir = direction; }

void Missile::Move()
{
	m_ypos += (m_moveSpeed * Time::GetDeltaTime()) * m_moveDir; 
	m_graphics->SetPosition((int)m_xpos, (int)m_ypos);
}

void Missile::CheckIfOOB()
{
	if(m_ypos < -m_height || m_ypos > (Settings::PlayfieldHeight + m_height))
	{ ToggleActive(false); }
}

bool Missile::IsActive()
{ return m_isActive; }