#include "Cover.h"

#include "Gui.h"

Cover::Cover(int xpos, int ypos) 
{ 
	m_graphics = Gui::Sprite(ImageLoader::CoverOne, xpos, ypos); 
	m_collisionObject = std::shared_ptr<CollisionObject>(new CollisionObject("Cover", m_graphics->GetRect()));
	CollisionManager::AddObject(m_collisionObject);

	m_hitPoints = 3;
}

Cover::~Cover() 
{
	m_collisionObject->ToggleRemove(true);
	CollisionManager::CleanupList();
	Gui::RemoveGuiObject(m_graphics);
}

void Cover::Update()
{
	if(m_collisionObject->GetCollisionData() == NULL)
	{ return; }
	
	ChangeGraphics();
	m_collisionObject->ClearCollisionData();
}

void Cover::ChangeGraphics()
{
	m_hitPoints--;
	int xpos = m_graphics->GetRect()->x;
	int ypos = m_graphics->GetRect()->y;
	Gui::RemoveGuiObject(m_graphics);

	if(m_hitPoints == 2)
	{ m_graphics = Gui::Sprite(ImageLoader::CoverTwo, xpos, ypos); }
	else if(m_hitPoints == 1)
	{ m_graphics = Gui::Sprite(ImageLoader::CoverThree, xpos, ypos); }
	else
	{
		m_collisionObject->ToggleRemove(true);
		CollisionManager::CleanupList();		
	}
}