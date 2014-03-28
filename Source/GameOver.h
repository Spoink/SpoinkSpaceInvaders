#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Gui.h"

class GameOver
{
	public:
		GameOver();
		~GameOver();

		void Initialize(int score);
		void Update();
		void Shutdown();

		bool IsDone();

	private:
		std::shared_ptr<RenderObject> m_header;
		std::shared_ptr<RenderObject> m_letterSelector;
		std::shared_ptr<RenderObject> m_nameLabel;
		std::shared_ptr<RenderObject> m_scoreLabel;
		std::shared_ptr<RenderObject> m_highscoreLabel;
		std::shared_ptr<RenderObject> m_subHeader;

		int m_score;
		std::string m_name;
		int m_namePos;
		bool m_isDone;

		void PrintHighscorePlace(int place);
		void PrintPlayerName();
		void ShiftNameUpwards();
		void ShiftNameDownwards();
		void ShiftNameLeft();
		void ShiftNameRight();
};

#endif GAMEOVER_H