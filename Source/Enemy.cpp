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

	m_moveSpeed = 100.0f;
	m_moveDir = 1;
}

Enemy::~Enemy()
{
	Gui::RemoveGuiObject(m_graphics);
}

void Enemy::Update()
{ 
	m_xpos += (m_moveSpeed * Time::GetDeltaTime()) * m_moveDir; 
	m_graphics->SetPosition(m_xpos, m_ypos);
}

bool Enemy::HasHitBounderies()
{
	if(m_xpos < 0 || m_xpos > (Settings::PlayfieldWidth - m_width))
	{ return true; }

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