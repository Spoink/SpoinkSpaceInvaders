#ifndef APP_H
#define APP_H

#include "Globals.h"

class App
{
public:
	App();
	virtual ~App();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Shutdown() = 0;

protected:
	int m_width;
	int m_height;
	std::string m_windowName;
	SDL_Surface* m_surface;
};

#endif APP_H