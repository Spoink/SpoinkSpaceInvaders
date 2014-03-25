#include "SDL_Game.h"

int main(int argc, char** argv)
{
	SDL_Game game;
	game.Initialize();
	game.Update();
	game.Shutdown();

	return 0;
}