#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "Global.h"

class SoundManager
{
	public:
		enum Music
		{
			MainLoop
		};
		
		enum Sounds
		{
			ButtonClick,
			RowCleared,
			Dropping
		};

		static SoundManager* Instance;

		SoundManager();
		~SoundManager();

		void PlayMusic(Music music, bool shouldLoop);
		void StopMusic();
		void PlayClip(Sounds sound, bool shouldLoop);

	private:
		std::vector<Mix_Music*> m_musicList;
		std::vector<Mix_Chunk*> m_soundList;
};

#endif SOUNDMANAGER_H