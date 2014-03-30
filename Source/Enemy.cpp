#include "Enemy.h"
#include "Gui.h"
#include "Settings.h"
#include "Time.h"
#include "ScoreManager.h"

Enemy::Enemy(EnemyType enemyType, std::shared_ptr<RenderObject> graphics)
{
	m_enemyType = enemyType;
	m_graphics = graphics;
	m_xpos = (float)m_graphics->GetRect()->x;
	m_ypos = (float)m_graphics->GetRect()->y;
	m_width = (float)m_graphics->GetRect()->w;

	m_collisionObject = std::shared_ptr<CollisionObject>(new CollisionObject("Enemy", m_graphics->GetRect()));
	CollisionManager::AddObject(m_collisionObject);

	m_moveSpeed = 100.0f;
	m_moveDir = 1;
	m_isAlive = true;
}

Enemy::~Enemy()
{
	Gui::RemoveGuiObject(m_graphics);
	m_collisionObject->ToggleRemove(true);
	CollisionManager::CleanupList();
}

void Enemy::Update()
{ 
	if(!m_isAlive)
	{ return; }

	m_xpos += (m_moveSpeed * Time::GetDeltaTime()) * m_moveDir; 
	m_graphics->SetPosition((int)m_xpos, (int)m_ypos);

	if(m_collisionObject->GetCollisionData() != NULL)
	{ Destroy(); }
}

bool Enemy::HasHitBounderies()
{
	if(m_xpos < 0)
	{  
		SetPosition(0, (int)m_ypos);
		return true;
	}
	else if(m_xpos > (Settings::PlayfieldWidth - m_width))
	{ 
		SetPosition((Settings::PlayfieldWidth - (int)m_width), (int)m_ypos);
		return true; 
	}

	return false;
}

void Enemy::SetPosition(int xpos, int ypos)
{ 
	m_xpos = (float)xpos;
	m_ypos = (float)ypos;
	m_graphics->SetPosition((int)m_xpos, (int)m_ypos);
}

void Enemy::SetMoveDir(int moveDir)
{ m_moveDir = moveDir; }

int Enemy::GetMoveDir()
{ return m_moveDir; }

bool Enemy::IsAlive()
{ return m_isAlive; }

void Enemy::Destroy()
{
	if(m_enemyType == EnemyType::EnemyType_One)
	{ ScoreManager::Instance->AddScore(10); }
	else if(m_enemyType == EnemyType::EnemyType_Two)
	{ ScoreManager::Instance->AddScore(20); }
	else if(m_enemyType == EnemyType::EnemyType_Three)
	{ ScoreManager::Instance->AddScore(25); }
	else
	{ ScoreManager::Instance->AddScore(30); }

	m_isAlive = false; 
}