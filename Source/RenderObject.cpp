#include "RenderObject.h"

RenderObject::RenderObject(SDL_Surface* image, int xpos, int ypos)
{ 
	m_image = image; 
	m_position = std::shared_ptr<SDL_Rect>(new SDL_Rect());
	m_position->x = xpos;
	m_position->y = ypos;
	m_position->w = m_image->w;
	m_position->h = m_image->h;
	m_destroy = false;
	m_isVisible = true;
}

RenderObject::~RenderObject()
{
	// DOES NOT FREE TEXT LABEL SURFACES!
}

SDL_Surface* RenderObject::GetImage()
{ return m_image; }

std::shared_ptr<SDL_Rect> RenderObject::GetRect()
{ return m_position; }

void RenderObject::SetPosition(int xpos, int ypos)
{
	m_position->x = xpos;
	m_position->y = ypos;
}

void RenderObject::SetDestroy()
{ m_destroy = true; }

bool RenderObject::ShouldDestroy()
{ return m_destroy; }

bool RenderObject::IsVisible()
{ return m_isVisible; }

void RenderObject::ToggleVisibility(bool isVisible)
{ m_isVisible = isVisible; }