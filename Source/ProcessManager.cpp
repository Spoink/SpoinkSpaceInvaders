#include "ProcessManager.h"

ProcessManager::ProcessManager() 
{
	m_firstProcess = NULL;
	m_lastProcess = NULL;
}

ProcessManager::~ProcessManager() 
{  PopAll(NULL); }

int ProcessManager::Push(void (*function)(void* callerPtr, Purpose purpose), void* callerPtr)
{
	if(function == NULL)
	{ return 0; }

	Process* newProcess = new Process();
	newProcess->Next = NULL;
	newProcess->Previous = m_lastProcess;
	newProcess->Function = function;

	if(m_firstProcess == NULL)
	{ 
		m_firstProcess = newProcess;
		newProcess->Id = 1;
	}
	else
	{
		newProcess->Id = m_lastProcess->Id + 1;
		m_lastProcess->Next = newProcess;
	}

	m_lastProcess = newProcess;
	newProcess->Function(callerPtr, Init_Purpose);
	return newProcess->Id;
}

bool ProcessManager::Pop(unsigned int id, void* callerPtr)
{
	Process* currentProcess;
	currentProcess = m_firstProcess;

	while(currentProcess != NULL)
	{
		if(currentProcess->Id == id)
		{
			if(currentProcess->Previous == NULL)
			{ m_firstProcess = currentProcess->Next; }
			else
			{ currentProcess->Previous->Next = currentProcess->Next; }

			if(currentProcess->Next == NULL)
			{ m_lastProcess = currentProcess->Previous; }
			else
			{ currentProcess->Next->Previous = currentProcess->Previous; }

			currentProcess->Function(callerPtr, Stop_Purpose);
			currentProcess->Next = NULL;
			currentProcess->Previous = NULL;
			
			delete currentProcess;
			return true;
		}

		currentProcess = currentProcess->Next;
	}

	return false;
}

bool ProcessManager::PopAll(void* callerPtr)
{
	Process* currentProcess = m_firstProcess;
	Process* popProcess;

	if(currentProcess == NULL)
	{ return false; }

	while(currentProcess != NULL)
	{
		popProcess = currentProcess;
		currentProcess = currentProcess->Next;
		Pop(popProcess->Id, NULL);
	}

	m_firstProcess = NULL;
	m_lastProcess = NULL;
}

bool ProcessManager::DoProcessing(void* callerPtr)
{
	if(m_firstProcess != NULL)
	{
		Process* currentProcess = m_firstProcess;
		while(currentProcess != NULL)
		{
			currentProcess->Function(callerPtr, Frame_Purpose);
			currentProcess = currentProcess->Next;
		}

		return true;
	}

	return false;
}