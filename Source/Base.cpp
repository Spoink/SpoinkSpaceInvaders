#include "Base.h"
#include "ImageLoader.h"
#include "Time.h"

    void Base::Initialize()
    {
        SDL_Init(SDL_INIT_EVERYTHING);

		m_renderer = std::unique_ptr<Renderer>(new Renderer());
        m_renderer->Initialize();

		m_imageLoader = std::unique_ptr<ImageLoader>(new ImageLoader());
		m_imageLoader->Initialize();

		m_gui = std::unique_ptr<Gui>(new Gui());

		m_events = std::unique_ptr<Events>(new Events());
		m_events->Initialize();

		m_soundManager = std::unique_ptr<SoundManager>(new SoundManager());

		m_highScore = std::unique_ptr<Highscore>(new Highscore());
		m_highScore->Initialize();

		m_mainMenu = std::unique_ptr<MainMenu>(new MainMenu());
		m_mainMenu->Initialize();

		m_game = std::unique_ptr<Game>(new Game());
		m_gameOver = std::unique_ptr<GameOver>(new GameOver());

		m_currentState = MainMenu_State;
		m_shouldExit = false;
		m_lastScore = 0;

		Time::Initialize();
    }

    void Base::Update()
    {
		while(!m_events->IsClosingApp() && !m_shouldExit)
        {
			m_events->Update();
			if(m_currentState == MainMenu_State)
			{ 
				m_mainMenu->Update(); 
				if(m_mainMenu->ShouldStart())
				{ SwitchToState(Game_State); }
				m_shouldExit = m_mainMenu->ShouldExit();
			}
			else if(m_currentState == Game_State)
			{ 
				m_game->Update(); 
				if(ScoreManager::Instance->IsGameOver())
				{
					m_lastScore = ScoreManager::Instance->GetScore();
					SwitchToState(GameOver_State); 
				}
				else if(m_game->GotoMenu())
				{ SwitchToState(MainMenu_State); }
			}
			else if(m_currentState == GameOver_State)
			{ 
				m_gameOver->Update(); 
				if(m_gameOver->IsDone())
				{ SwitchToState(MainMenu_State); }
			}
            m_renderer->Update();
			Time::UpdateDeltaTime();
        }
    }

    void Base::Shutdown()
    {
		ShutdownState(m_currentState);

		m_highScore->Shutdown();
		m_events->Shutdown();
        m_renderer->Shutdown();
		m_imageLoader->Shutdown();
		
        SDL_Quit();
    }

	void Base::SwitchToState(MainState newState)
	{
		ShutdownState(m_currentState);
		m_currentState = newState;
		InitializeState(m_currentState);
	}

	void Base::InitializeState(MainState state)
	{
		if(state == MainMenu_State)
		{ m_mainMenu->Initialize(); }
		else if(state == Game_State)
		{ m_game->Initialize(); }
		else if(state == GameOver_State)
		{ m_gameOver->Initialize(m_lastScore); }	
	}
	
	void Base::ShutdownState(MainState state)
	{
		if(state == MainMenu_State)
		{ m_mainMenu->Shutdown(); }
		else if(state == Game_State)
		{ m_game->Shutdown(); }
		else if(state == GameOver_State)
		{ m_gameOver->Shutdown(); }		
	}
