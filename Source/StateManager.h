#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "Globals.h"
#include "Purpose.h"

struct State
{
	State* Previous;
	void (*Function) (void* callerPtr, Purpose purpose);

	State()
	{
		Previous = NULL;
		Function = NULL;
	}

	~State()
	{ delete Previous; }
};

class StateManager
{
public:
	StateManager();
	~StateManager();

	bool Push(void(*function)(void* callerPtr, Purpose purpose), void* callerPtr = NULL);
	bool Pop(void* callerPtr = NULL);
	bool PopAll(void* callerPtr = NULL);
	bool DoProcessing(void* callerPtr = NULL);

private:
	State* m_currentState;
};

#endif STATEMANAGER_H