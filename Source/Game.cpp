#include "Game.h"

#include "Settings.h"
#include "Gui.h"
#include "Events.h"
#include "SoundManager.h"
#include "Highscore.h"

#pragma region Base

void Game::Initialize()
{
	m_scoreManager = std::unique_ptr<ScoreManager>(new ScoreManager());
	m_scoreManager->Initialize();

	m_player = std::unique_ptr<Player>(new Player());
	m_squad = std::unique_ptr<EnemySquad>(new EnemySquad());

	m_scoreText = std::shared_ptr<RenderObject>(Gui::Label("Score: ", 40, 40, Gui::Color::White));
	m_scoreLabel = std::shared_ptr<RenderObject>(Gui::Label("0", 120, 40, Gui::Color::White));

	m_oldScore = 0;
	m_gotoMenu = false;

	SoundManager::Instance->PlayMusic(SoundManager::Music::MainLoop, true);
}

void Game::Update()
{
	if(m_scoreManager->IsGameOver())
	{ return; }

	if(Events::Instance->IsKeyDown(KeyCode::Key_Escape))
	{ 
		m_gotoMenu = true; 
		SoundManager::Instance->PlayClip(SoundManager::Sounds::ButtonClick, false);
	}

	m_player->Update();
	m_squad->Update();
	UpdateScore();
}

void Game::Shutdown()
{
	Gui::RemoveGuiObject(m_scoreLabel);
	Gui::RemoveGuiObject(m_scoreText);

	m_scoreManager->Cleanup();
	m_scoreManager->Shutdown(); 

	SoundManager::Instance->StopMusic();
	m_player.reset();
	m_squad.reset();
}

bool Game::GotoMenu()
{ return m_gotoMenu; }

#pragma endregion

#pragma region Privates

void Game::UpdateScore()
{
	if(m_oldScore == m_scoreManager->GetScore())
	{ return; }

	Gui::RemoveGuiObject(m_scoreLabel);
	m_oldScore = m_scoreManager->GetScore();
	m_scoreLabel = Gui::Label("" + std::to_string(m_oldScore), 120, 40, Gui::Color::White);
}

#pragma endregion