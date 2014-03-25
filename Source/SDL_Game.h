#ifndef SDL_Game_H
#define SDL_Game_H

#include "SystemCore.h"
#include "Globals.h"

class SDL_Game : App
{
public:
	SDL_Game();
	~SDL_Game();

	void Initialize();
	void Update();
	void Shutdown();

private:
	SDL_Window* m_window;
};

#endif SDL_Game_H