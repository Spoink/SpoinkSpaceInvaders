#include <SDL.h>
#include <time.h>

#include "Time.h"

float Time::oldTime;
float Time::deltaTime;

void Time::Initialize()
{ oldTime = GetTime(); }

void Time::UpdateDeltaTime()
{ 
	deltaTime = GetTime() - oldTime;
	oldTime = GetTime();
}

float Time::GetTime()
{ return SDL_GetTicks() / 1000.0f; }

int Time::GetRealTime()
{
	time_t currentTime;
	time(&currentTime);
	return (int)currentTime;
}

float Time::GetDeltaTime()
{ return deltaTime; }