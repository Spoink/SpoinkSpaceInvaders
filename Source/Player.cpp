#include "Player.h"

#include "Events.h"
#include "Time.h"
#include "Settings.h"
#include "ScoreManager.h"

Player::Player() 
{
	m_graphics = Gui::Sprite(ImageLoader::Player, 0, 0);

	m_startX = 100;
	m_startY = 550;
	SetPosition((float)m_startX, (float)m_startY);

	m_collisionObject = std::shared_ptr<CollisionObject>(new CollisionObject("Player", CollisionObject::CollisionLayer::Player, m_graphics->GetRect()));
	CollisionManager::AddObject(m_collisionObject);

	m_speed = 340.0f;
	m_lastFire = 0.0f;
	m_fireRate = 0.1f;
	m_lives = 3;

	for(unsigned int i = 0; i < 10; i++)
	{
		std::shared_ptr<RenderObject> graphics = Gui::Sprite(ImageLoader::PlayerMissile, -50, -50);
		m_listOfMissiles.push_back(std::unique_ptr<Missile>(new Missile(CollisionObject::CollisionLayer::Player, graphics)));
	}
}

Player::~Player() 
{
	m_collisionObject->ToggleRemove(true);
	CollisionManager::CleanupList();
	Gui::RemoveGuiObject(m_graphics);
	m_listOfMissiles.clear();
}

void Player::Update() 
{
	if(Events::Instance->IsKey(KeyCode::Key_Left))
	{ MoveToLeft(); }
	else if(Events::Instance->IsKey(KeyCode::Key_Right))
	{ MoveToRight(); }
	
	if(Events::Instance->IsKeyDown(KeyCode::Key_Space))
	{ FireMissile(); }

	for(unsigned int i = 0; i < m_listOfMissiles.size(); i++)
	{ m_listOfMissiles[i]->Update(); }

	if(m_collisionObject->GetCollisionData() != NULL)
	{ LoseLife(); }
}

int Player::GetLives()
{ return m_lives; }

void Player::MoveToLeft()
{
	float newX = m_xpos - (m_speed * Time::GetDeltaTime());
	if(newX < 0)
	{ return; }

	SetPosition(newX, m_ypos);
}

void Player::MoveToRight()
{
	float newX = m_xpos + (m_speed * Time::GetDeltaTime());
	if(newX > (Settings::PlayfieldWidth - m_graphics->GetRect()->w))
	{ return; }

	SetPosition(newX, m_ypos);
}

void Player::SetPosition(float xpos, float ypos)
{  
	m_xpos = xpos;
	m_ypos = ypos;
	m_graphics->SetPosition((int)m_xpos, (int)m_ypos);
}

void Player::FireMissile()
{
	if(Time::GetTime() - m_lastFire < m_fireRate)
	{ return; }

	for(unsigned int i = 0; i < m_listOfMissiles.size(); i++)
	{
		if(m_listOfMissiles[i]->IsActive())
		{ continue; }

		m_listOfMissiles[i]->SetPosition((int)m_xpos + 22, (int)m_ypos);
		m_listOfMissiles[i]->SetMoveDirection(-1);
		m_listOfMissiles[i]->ToggleActive(true);
		break;
	}

	m_lastFire = Time::GetTime();
	ScoreManager::Instance->AddScore(-5);
}

void Player::LoseLife()
{ 
	m_lives--; 
	SetPosition((float)m_startX, (float)m_startY);

	if(m_lives == 0)
	{ ScoreManager::Instance->SetGameOver(); }
}