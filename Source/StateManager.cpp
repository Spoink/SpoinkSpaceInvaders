#include "StateManager.h"

StateManager::StateManager()
{ m_currentState = NULL; }

StateManager::~StateManager() 
{ PopAll(NULL); }

bool StateManager::Push(void(*function)(void* callerPtr, Purpose purpose), void* callerPtr)
{
	if(function == NULL)
	{ return false; }

	State* newState = new State();
	newState->Previous = m_currentState;
	newState->Function = function;

	m_currentState = newState;
	newState->Function(callerPtr, Init_Purpose);

	return true;
}

bool StateManager::Pop(void* callerPtr)
{
	if(m_currentState == NULL)
	{ return false; }

	m_currentState->Function(callerPtr, Stop_Purpose);
	State* deleteState = m_currentState;
	m_currentState = m_currentState->Previous;

	
	deleteState->Previous = NULL;
	delete deleteState;

	return true;
}

bool StateManager::PopAll(void* callerPtr)
{
	if(m_currentState == NULL)
	{ return false; }

	while(m_currentState != NULL)
	{ Pop(callerPtr); }

	return true;
}

bool StateManager::DoProcessing(void* callerPtr)
{
	if(m_currentState == NULL)
	{ return false; }

	m_currentState->Function(callerPtr, Frame_Purpose);
	return true;
}