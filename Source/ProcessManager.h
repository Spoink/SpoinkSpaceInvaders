#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "Globals.h"
#include "Purpose.h"

struct Process
{
	Process* Next;
	Process* Previous;

	void (*Function)(void* calllerPtr, Purpose purpose);
	unsigned int Id;

	Process()
	{
		Previous = NULL;
		Next = NULL;
		Function = NULL;
		Id = 0;
	}

	~Process()
	{
		delete Previous;
		delete Next;
	}
};

class ProcessManager
{
public:
	ProcessManager();
	~ProcessManager();

	int Push(void (*function)(void* callerPtr, Purpose purpose), void* callerPtr = NULL);
	bool Pop(unsigned int id, void* callerPtr = NULL);
	bool PopAll(void* callerPtr = NULL);
	bool DoProcessing(void* callerPtr = NULL);

private:
	Process* m_firstProcess;
	Process* m_lastProcess;
};

#endif PROCESSMANAGER_H