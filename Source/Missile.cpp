#include "Missile.h"
#include "Time.h"
#include "Settings.h"
#include "Gui.h"

Missile::Missile(std::shared_ptr<RenderObject> graphics) 
{ 
	m_graphics = graphics; 
	m_isActive = false;

	m_xpos = m_graphics->GetRect()->x;
	m_ypos = m_graphics->GetRect()->y;
	m_height = m_graphics->GetRect()->h;
	m_moveDir = 1;
	m_moveSpeed = 400.0f;

	m_graphics->ToggleVisibility(false);
}

Missile::~Missile() 
{ Gui::RemoveGuiObject(m_graphics); }

void Missile::Update()
{ 
	if(!m_isActive)
	{ return; }

	Move();
	CheckIfOOB();
}

void Missile::ToggleActive(bool isActive)
{ 
	m_isActive = isActive; 
	m_graphics->ToggleVisibility(m_isActive);
}

void Missile::SetPosition(int xpos, int ypos)
{ 
	m_xpos = xpos;
	m_ypos = ypos;
	m_graphics->SetPosition(m_xpos, m_ypos); 
}

void Missile::SetMoveDirection(int direction)
{ m_moveDir = direction; }

void Missile::Move()
{
	m_ypos += (m_moveSpeed * Time::GetDeltaTime()) * m_moveDir; 
	m_graphics->SetPosition(m_xpos, m_ypos);
}

void Missile::CheckIfOOB()
{
	if(m_ypos < -m_height || m_ypos > (Settings::PlayfieldHeight + m_height))
	{ 
		m_isActive = false; 
		m_graphics->ToggleVisibility(false);
	}
}

bool Missile::IsActive()
{ return m_isActive; }