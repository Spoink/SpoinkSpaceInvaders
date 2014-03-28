#ifndef EVENTS_H
#define EVENTS_H

#include "Global.h"

#include "KeyCode.h"

class Events
{
	public:
		static Events* Instance;
		
		void Initialize();
		void Update();
		void Shutdown();

		bool IsClosingApp();
		bool IsKeyDown(KeyCode keyCode);
		bool IsKey(KeyCode keyCode);

	private:
		SDL_Event* m_sdlEvents;
		bool m_isClosingApp;
		std::map<KeyCode, char> m_keyList;

		void SortingKeys(std::vector<KeyCode> keys);
};

#endif EVENTS_H