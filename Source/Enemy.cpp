#include "Enemy.h"
#include "Gui.h"
#include "Settings.h"
#include "Time.h"

Enemy::Enemy(std::shared_ptr<RenderObject> graphics)
{
	m_graphics = graphics;
	m_xpos = m_graphics->GetRect()->x;
	m_ypos = m_graphics->GetRect()->y;
	m_width = m_graphics->GetRect()->w;

	m_collisionObject = std::shared_ptr<CollisionObject>(new CollisionObject("Enemy", m_graphics->GetRect()));
	CollisionManager::AddObject(m_collisionObject);

	m_moveSpeed = 100.0f;
	m_moveDir = 1;
	m_isAlive = true;
}

Enemy::~Enemy()
{
	Gui::RemoveGuiObject(m_graphics);
	m_collisionObject->SetRemove();
	CollisionManager::CleanupList();
}

void Enemy::Update()
{ 
	if(!m_isAlive)
	{ return; }

	m_xpos += (m_moveSpeed * Time::GetDeltaTime()) * m_moveDir; 
	m_graphics->SetPosition(m_xpos, m_ypos);

	if(m_collisionObject->GetCollisionData() != NULL)
	{ Destroy(); }
}

bool Enemy::HasHitBounderies()
{
	if(m_xpos < 0)
	{  
		SetPosition(0, m_ypos);
		return true;
	}
	else if(m_xpos > (Settings::PlayfieldWidth - m_width))
	{ 
		SetPosition((Settings::PlayfieldWidth - m_width), m_ypos);
		return true; 
	}

	return false;
}

void Enemy::SetPosition(int xpos, int ypos)
{ 
	m_xpos = xpos;
	m_ypos = ypos;
	m_graphics->SetPosition(m_xpos, m_ypos);
}

void Enemy::SetMoveDir(int moveDir)
{ m_moveDir = moveDir; }

int Enemy::GetMoveDir()
{ return m_moveDir; }

bool Enemy::IsAlive()
{ return m_isAlive; }

void Enemy::Destroy()
{ m_isAlive = false; }