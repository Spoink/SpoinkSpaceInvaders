#ifndef GAME_H
#define GAME_H

#include "Global.h"
#include "Player.h"
#include "EnemySquad.h"
#include "CollisionManager.h"
#include "SpecialEnemy.h"
#include "Cover.h"
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
		std::unique_ptr<EnemySquad> m_squad;
		std::unique_ptr<CollisionManager> m_collisionManager;
		std::unique_ptr<SpecialEnemy> m_specialEnemy;
		std::vector<std::unique_ptr<Cover>> m_listOfCovers;

		std::shared_ptr<RenderObject> m_scoreText;
		std::shared_ptr<RenderObject> m_scoreLabel;

		int m_oldScore;
		bool m_gotoMenu;

		void UpdateScore();
};

#endif GAME_H