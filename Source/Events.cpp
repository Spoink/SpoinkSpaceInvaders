#include "Events.h"
#include "Time.h"

Events* Events::Instance;

void Events::Initialize()
{ 
	m_sdlEvents = new SDL_Event(); 
	m_isClosingApp = false;

	Instance = this;
}

void Events::Update()
{
	std::vector<KeyCode> keysInEvents;

	while(SDL_PollEvent(m_sdlEvents) > 0)
	{
		if(m_sdlEvents->type == SDL_QUIT)
		{ m_isClosingApp = true; }
		else if(m_sdlEvents->type == SDL_KEYDOWN)
		{ 
			KeyCode keyCode = (KeyCode)m_sdlEvents->key.keysym.sym;
			m_keyList[keyCode] = 'd';
			keysInEvents.push_back(keyCode);
		}
		else if(m_sdlEvents->type == SDL_KEYUP)
		{
			KeyCode keyCode = (KeyCode)m_sdlEvents->key.keysym.sym;
			m_keyList[keyCode] = 'u';
			keysInEvents.push_back(keyCode);
		}
	}

	SortingKeys(keysInEvents);
}

void Events::Shutdown()
{
	delete(m_sdlEvents);
	m_sdlEvents = NULL;
}

bool Events::IsClosingApp()
{ return m_isClosingApp; }

bool Events::IsKeyDown(KeyCode keyCode)
{ return m_keyList[keyCode] == 'd'; }

bool Events::IsKey(KeyCode keyCode)
{ return m_keyList[keyCode] == 'd' || m_keyList[keyCode] == 'h'; }

void Events::SortingKeys(std::vector<KeyCode> keys)
{
	for(std::map<KeyCode, char>::iterator it = m_keyList.begin(); it != m_keyList.end(); it++)
	{
		if(it->second == 'u')
		{
			bool foundKey = false;
			for(unsigned int i = 0; i < keys.size(); i++)
			{
				if(keys[i] == it->first)
				{
					foundKey = true;
					break;
				}
			}

			if(!foundKey)
			{ it->second = 'n'; }
		}
		else if(it->second == 'd')
		{
			bool foundKey = false;
			for(unsigned int i = 0; i < keys.size(); i++)
			{
				if(keys[i] == it->first)
				{
					foundKey = true;
					break;
				}
			}

			if(!foundKey)
			{ it->second = 'h'; }
		}
	}	
}