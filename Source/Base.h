#ifndef BASE_H
#define BASE_H

#include "Global.h"

#include "Gui.h"
#include "Events.h"
#include "MainMenu.h"
#include "Game.h"
#include "GameOver.h"
#include "Renderer.h"
#include "SoundManager.h"
#include "Highscore.h"

class Base
{
    public:
        void Initialize();
        void Update();
        void Shutdown();

    private:
		enum MainState
		{
			MainMenu_State,
			Game_State,
			GameOver_State
		};
		
		std::unique_ptr<ImageLoader> m_imageLoader;
		std::unique_ptr<Gui> m_gui;
		std::unique_ptr<Events> m_events;
		std::unique_ptr<MainMenu> m_mainMenu;
		std::unique_ptr<Game> m_game;
		std::unique_ptr<GameOver> m_gameOver;
        std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<SoundManager> m_soundManager;
		std::unique_ptr<Highscore> m_highScore;

		MainState m_currentState;
		bool m_shouldExit;
		int m_lastScore;

		void SwitchToState(MainState newState);
		void InitializeState(MainState state);
		void ShutdownState(MainState state);
};

#endif BASE_H