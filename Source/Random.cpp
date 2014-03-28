#include <stdlib.h>

#include "Random.h"
#include "Time.h"

bool Random::isInitialized = false;

int Random::Range(int start, int end)
{ 
	if(!isInitialized)
	{
		srand(Time::GetRealTime());
		isInitialized = true;
	}

	return rand() % end + start;
}