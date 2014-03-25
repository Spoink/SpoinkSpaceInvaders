#include "SDL_Game.h"

SDL_Game::SDL_Game() {}

SDL_Game::~SDL_Game() {}

void SDL_Game::Initialize()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{ exit(1); }

	m_width = 800;
	m_height= 600;
	m_windowName = "SDL_Game";

	m_window = SDL_CreateWindow(m_windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, NULL);
	m_surface = SDL_GetWindowSurface(m_window);
}

void SDL_Game::Update()
{
	SDL_Delay(2000);
}

void SDL_Game::Shutdown()
{
	SDL_FreeSurface(m_surface);
	SDL_DestroyWindow(m_window);
	exit(0);
}