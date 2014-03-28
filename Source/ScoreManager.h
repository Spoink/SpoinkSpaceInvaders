#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include "Global.h"

class ScoreManager
{
	public:
		static ScoreManager* Instance;
		
		void Initialize();
		void Shutdown();

		int GetScore();
		bool IsGameOver();
		void Cleanup();

	private:
		int m_currentScore;
		bool m_gameOver;
};

#endif SCOREMANAGER_H