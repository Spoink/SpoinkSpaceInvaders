#include "SpecialEnemy.h"
#include "Random.h"
#include "Time.h"
#include "Gui.h"
#include "Settings.h"

SpecialEnemy::SpecialEnemy() 
{
	m_enemy = NULL;
	m_nextSpawn = Time::GetTime() + Random::Range(5, 10);

	m_xpos = 0.0f;
	m_ypos = 0.0f;
	m_moveSpeed = 150.0f;
}

SpecialEnemy::~SpecialEnemy() {}

void SpecialEnemy::Update()
{
	if(m_enemy == NULL)
	{ SpawnEnemy(); }
	else
	{ 
		MoveEnemy(); 
		CheckIfOOB();
		CheckIfHit();
	}
}

void SpecialEnemy::SpawnEnemy()
{
	if(Time::GetTime() < m_nextSpawn)
	{ return; }

	m_xpos = -100.0f;
	m_ypos = 60.0f;
	
	std::shared_ptr<RenderObject> graphics = Gui::Sprite(ImageLoader::BigShip, (int)m_xpos, (int)m_ypos);
	m_enemy = std::unique_ptr<Enemy>(new Enemy(Enemy::EnemyType::EnemyType_Special, graphics));
	
	m_width = (float)graphics->GetRect()->w;
}

void SpecialEnemy::MoveEnemy()
{
	m_xpos += m_moveSpeed * Time::GetDeltaTime();
	m_enemy->SetPosition((int)m_xpos, (int)m_ypos);
}

void SpecialEnemy::CheckIfOOB()
{
	if(m_xpos < Settings::PlayfieldWidth + m_width)
	{ return; }

	m_nextSpawn = Time::GetTime() + Random::Range(5, 10);
	m_enemy = NULL;
}

void SpecialEnemy::CheckIfHit()
{
	if(m_enemy == NULL)
	{ return; }
	if(!m_enemy->IsHit())
	{ return; }

	m_enemy->Destroy();
	m_nextSpawn = Time::GetTime() + Random::Range(5, 10);
	m_enemy = NULL;
}