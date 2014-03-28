#include "Player.h"

#include "Events.h"
#include "Time.h"

Player::Player() 
{
	m_graphics = Gui::Sprite(ImageLoader::Player, 0, 0);

	m_xpos = 100.0f;
	m_ypos = 500.0f;
	m_graphics->SetPosition((int)m_xpos, (int)m_ypos);

	m_speed = 340.0f;
}

Player::~Player() 
{
	Gui::RemoveGuiObject(m_graphics);
}

void Player::Update() 
{
	if(Events::Instance->IsKey(KeyCode::Key_Left))
	{ MoveToLeft(); }
	else if(Events::Instance->IsKey(KeyCode::Key_Right))
	{ MoveToRight(); }
}

void Player::MoveToLeft()
{
	m_xpos -= m_speed * Time::GetDeltaTime();
	m_graphics->SetPosition(m_xpos, m_ypos);
}

void Player::MoveToRight()
{
	m_xpos += m_speed * Time::GetDeltaTime();
	m_graphics->SetPosition(m_xpos, m_ypos);	
}