#include "Settings.h"

#include "Renderer.h"
#include "ImageLoader.h"
#include "TextManager.h"

std::vector<std::shared_ptr<RenderObject>> Renderer::renderQueue;

void Renderer::Initialize()
{
    m_window = SDL_CreateWindow("Spoink Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	m_mainSurface = SDL_GetWindowSurface(m_window);
		
	ImageLoader::PixelFormat = m_mainSurface->format;
	TextManager::PixelFormat = m_mainSurface->format;
	
	m_backgroundColor = SDL_MapRGB(m_mainSurface->format, 0, 0, 0);
}

void Renderer::Update()
{
	SDL_FillRect(m_mainSurface, NULL, m_backgroundColor);

	for(int i = 0; i < renderQueue.size(); i++)
	{
		if(!renderQueue[i]->IsVisible())
		{ continue; }
		SDL_BlitSurface(renderQueue[i]->GetImage(), NULL, m_mainSurface, renderQueue[i]->GetRect().get()); 
	}

	SDL_UpdateWindowSurface(m_window);
}

void Renderer::Shutdown()
{
	SDL_FreeSurface(m_mainSurface);
	SDL_DestroyWindow(m_window);
}

void Renderer::AddToQueue(std::shared_ptr<RenderObject> image)
{ renderQueue.push_back(image); }

void Renderer::CleanUpQueue()
{ 
	for(int i = renderQueue.size() - 1; i > -1; i--)
	{ 
		if(renderQueue[i]->ShouldDestroy())
		{ renderQueue.erase(renderQueue.begin() + i); }
	}
}
