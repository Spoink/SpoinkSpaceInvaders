#include "Settings.h"

#include "SoundManager.h"

SoundManager* SoundManager::Instance;

SoundManager::SoundManager() 
{ 
	Instance = this; 
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	
	m_musicList.push_back(Mix_LoadMUS("Assets/Sounds/Music.mp3"));
	
	m_soundList.push_back(Mix_LoadWAV("Assets/Sounds/ButtonPress.Wav"));
	m_soundList.push_back(Mix_LoadWAV("Assets/Sounds/RowCleared.Wav"));
	m_soundList.push_back(Mix_LoadWAV("Assets/Sounds/Dropping.Wav"));
}

SoundManager::~SoundManager() 
{
	for(unsigned int i = 0; i < m_musicList.size(); i++)
	{ Mix_FreeMusic(m_musicList[i]); }
	for(unsigned int i = 0; i < m_soundList.size(); i++)
	{ Mix_FreeChunk(m_soundList[i]); }
}

void SoundManager::PlayMusic(Music music, bool shouldLoop)
{
	if(!Settings::IsMusicOn)
	{ return; }

	if(shouldLoop)
	{ Mix_PlayMusic(m_musicList[music], -1); }
	else
	{ Mix_PlayMusic(m_musicList[music], 1); }
}

void SoundManager::StopMusic()
{ Mix_PauseMusic(); }

void SoundManager::PlayClip(Sounds sound, bool shouldLoop)
{
	if(!Settings::IsSoundOn)
	{ return; }

	if(shouldLoop)
	{ Mix_PlayChannel(-1, m_soundList[sound], -1); }
	else
	{ Mix_PlayChannel(-1, m_soundList[sound], 0); }
}