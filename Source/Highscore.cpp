#include "Highscore.h"

#include "FileIO.h"

Highscore* Highscore::Instance = NULL;

Highscore::Highscore()
{ m_highscoreCount = 5; }

Highscore::~Highscore() {}

void Highscore::Initialize()
{
	Instance = this; 
	m_filePath = "Assets/Misc/Highscore.score";
	ReadHighscore();
}

void Highscore::Shutdown()
{ WriteHighscore(); }

void Highscore::ReadHighscore()
{
	FILE* file = FileIO::OpenReadableFile(m_filePath);
	if(file == NULL)
	{ return; }

	m_highscore.clear();

	int highscoreLength = FileIO::ReadIntFromFile(file);
	for(int i = 0; i < highscoreLength; i++)
	{
		int stringLength = FileIO::ReadIntFromFile(file);
		std::string name = FileIO::ReadStringFromFile(file, stringLength);
		int score = FileIO::ReadIntFromFile(file);

		m_highscore.push_back(HighscoreData(name, score));
	}

	FileIO::CloseFile(file);
}

void Highscore::WriteHighscore()
{
	FILE* file = FileIO::OpenWriteableFile(m_filePath);

	FileIO::WriteIntToFile(file, m_highscore.size());
	for(unsigned int i = 0; i < m_highscore.size(); i++)
	{
		std::string name = m_highscore[i].Name;
		FileIO::WriteIntToFile(file, name.length());
		FileIO::WriteStringToFile(file, name);
		FileIO::WriteIntToFile(file, m_highscore[i].Score);
	}

	FileIO::CloseFile(file);
}

void Highscore::AddToHighscore(std::string name, int score)
{
	HighscoreData newScore(name, score);

	bool isInserted = false;
	for(unsigned int i = 0; i < m_highscore.size(); i++)
	{
		if(newScore.Score > m_highscore[i].Score)
		{
			m_highscore.insert(m_highscore.begin() + i, newScore);
			isInserted = true;
			break;
		}
	}

	if(isInserted)
	{ return; }

	if(m_highscore.size() < m_highscoreCount)
	{ m_highscore.push_back(newScore); }
}

int Highscore::GetHighscorePlace(int score)
{ 
	int place = -1;
	for(unsigned int i = 0; i < m_highscore.size(); i++)
	{
		if(score > m_highscore[i].Score)
		{
			place = i + 1;
			break;
		}
	}

	if(place > -1)
	{ return place; }

	if(m_highscore.size() < m_highscoreCount)
	{ return m_highscore.size() + 1; }

	return -1;
}

std::vector<HighscoreData> Highscore::GetHighscore()
{ return m_highscore; }