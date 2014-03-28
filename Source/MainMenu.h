#ifndef MAINMENU_H
#define MAINMENU_H

#include "Global.h"

#include "Gui.h"

class MainMenu
{
	public:
		MainMenu();
		~MainMenu();

		void Initialize();
		void Update();
		void Shutdown();

		bool ShouldStart();
		bool ShouldExit();

	private:
		std::shared_ptr<RenderObject> m_header;
		std::shared_ptr<RenderObject> m_menuOptionOne;
		std::shared_ptr<RenderObject> m_menuOptionTwo;
		std::shared_ptr<RenderObject> m_menuSelector;
		std::shared_ptr<RenderObject> m_subHeader;
		std::shared_ptr<RenderObject> m_highscoreLabel;
		std::vector<std::shared_ptr<RenderObject>> m_highscoreObjects;
		bool m_startGame;
		bool m_exitGame;
		int m_menuOption;

		void GenerateHighscore();
		void ChooseNextMenuOption();
};

#endif MAINMENU_H