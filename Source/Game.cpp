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

	m_scoreText = std::shared_ptr<RenderObject>(Gui::Label("Score: ", 40, 40, Gui::Color::White));
	m_scoreLabel = std::shared_ptr<RenderObject>(Gui::Label("0", 120, 40, Gui::Color::White));
	m_highscoreLabel = std::shared_ptr<RenderObject>(Gui::Label("Highscore", 550, 40, Gui::Color::White));

	m_oldScore = 0;
	m_gotoMenu = false;

	SoundManager::Instance->PlayMusic(SoundManager::Music::MainLoop, true);
	GenerateHighscoreList();
	UpdateHighscore();
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
	UpdateScore();
}

void Game::Shutdown()
{
	Gui::RemoveGuiObject(m_scoreLabel);
	Gui::RemoveGuiObject(m_scoreText);
	Gui::RemoveGuiObject(m_highscoreLabel);
	Gui::RemoveGuiObject(m_playerHighscoreLabel);

	for(unsigned int i = 0; i < m_highscoreObjs.size(); i++)
	{ Gui::RemoveGuiObject(m_highscoreObjs[i]); }
	m_highscoreObjs.clear();

	m_scoreManager->Cleanup();
	m_scoreManager->Shutdown(); 

	SoundManager::Instance->StopMusic();
	m_player.reset();
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

	UpdateHighscore();
}

void Game::GenerateHighscoreList()
{
	std::vector<HighscoreData> highscore = Highscore::Instance->GetHighscore();
	for(unsigned int i = 0; i < highscore.size(); i++)
	{ 
		std::shared_ptr<RenderObject> obj = Gui::Label(highscore[i].Name + " " + std::to_string(highscore[i].Score), 550, 70 + (i * 30), Gui::Color::White); 
		m_highscoreObjs.push_back(obj);
	}

	m_playerHighscoreLabel = Gui::Label("YOU 0", 550, 70 + (highscore.size() * 30), Gui::Color::White);
}

void Game::UpdateHighscore()
{
	int place = Highscore::Instance->GetHighscorePlace(m_oldScore);
	Gui::RemoveGuiObject(m_playerHighscoreLabel);

	if(place == -1)
	{ m_playerHighscoreLabel = Gui::Label("YOU " + std::to_string(m_oldScore), 550, 70 + (m_highscoreObjs.size() * 30), Gui::Color::White); }
	else
	{
		for(int i = 0; i < 10; i++)
		{
			if(i > m_highscoreObjs.size())
			{ break; }

			if((place - 1) == i)
			{ m_playerHighscoreLabel = Gui::Label("YOU " + std::to_string(m_oldScore), 550, 70 + (i * 30), Gui::Color::White); }
			else if((place - 1) < i)
			{ m_highscoreObjs[i - 1]->SetPosition(550, 70 + (i * 30)); }
		}
	}
}

#pragma endregion