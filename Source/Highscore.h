#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "Global.h"

class HighscoreData
{
	public: 
		HighscoreData(std::string name, int score) 
		{
			Name = name;
			Score = score;
		}

		~HighscoreData() {}

		std::string Name;
		int Score;
};

class Highscore
{
	public:
		static Highscore* Instance;
		
		Highscore();
		~Highscore();

		void Initialize();
		void Shutdown();

		void ReadHighscore();
		void WriteHighscore();
		void AddToHighscore(std::string name, int score);
		int GetHighscorePlace(int score);
		std::vector<HighscoreData> GetHighscore();

	private:
		std::string m_filePath;
		std::vector<HighscoreData> m_highscore;
};

#endif HIGHSCORE_H