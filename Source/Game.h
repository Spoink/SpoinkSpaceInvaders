#ifndef GAME_H
#define GAME_H

#include "Global.h"
#include "Player.h"
#include "ScoreManager.h"
#include "TextManager.h"

class Game
{
	public:
		void Initialize();
		void Update();
		void Shutdown();

		bool GotoMenu();

	private:
		std::unique_ptr<ScoreManager> m_scoreManager;
		std::unique_ptr<Player> m_player;

		std::shared_ptr<RenderObject> m_scoreText;
		std::shared_ptr<RenderObject> m_scoreLabel;
		std::shared_ptr<RenderObject> m_playerHighscoreLabel;
		std::shared_ptr<RenderObject> m_highscoreLabel;
		std::vector<std::shared_ptr<RenderObject>> m_highscoreObjs;

		int m_oldScore;
		bool m_gotoMenu;

		void UpdateScore();
		void GenerateHighscoreList();
		void UpdateHighscore();
};

#endif GAME_H